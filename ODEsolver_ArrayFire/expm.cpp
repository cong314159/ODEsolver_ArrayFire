#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "expm.h"
#include "trace.h"
#include "PadeApprox.h"
#include "expn.h"
#include "MatrixPower.h"

af::array expm(af::array a)
{
	double theta_table[] = { 1.495585217958292e-2,2.539398330063230e-1,9.504178996162932e-1,2.097847961257068e0,5.371920351148152e0 };
	int m_table[] = { 3,5,7,9,13 };
	double b[] = { 64764752532480000, 32382376266240000, 7771770303897600, 1187353796428800, 129060195264000, 10559470521600, 670442572800, 33522128640, 1323241920, 40840800, 960960, 16380, 182, 1 };
	af::cdouble mu = trace(a);
	a = a - (mu * af::identity(a.dims(0), a.dims(1)));
	for (int id = 0; id < 5; id++)
	{
		if (af::norm(a, AF_NORM_VECTOR_1) <= theta_table[id])
		{
			af::array X = padeApprox(a, m_table[id]);
			return expn(mu) * X;
		}
	}
	int d = 1;
	int s = 0;
	while (af::norm(a / d, AF_NORM_VECTOR_1) > theta_table[4])
	{
		d *= 2;
		s += 1;
	}
	//std::cout << af::norm(a / d, AF_NORM_VECTOR_1) << ", " << d << ", " << s << std::endl;

	a = a / d;

	af::array a2 = matmul(a, a);
	af::array a4 = matmul(a2, a2);
	af::array a6 = matmul(a2, a4);
	af::array U = matmul(a, (matmul(a6, (b[13] * a6 + b[11] * a4 + b[9] * a2)) + b[7] * a6 + b[5] * a4 + b[3] * a2 + b[1] * af::identity(a.dims(0), a.dims(1))));
	af::array V = matmul(a6, (b[12] * a6 + b[10] * a4 + b[8] * a2)) + b[6] * a6 + b[4] * a4 + b[2] * a2 + b[0] * af::identity(a.dims(0), a.dims(1));

	af::array r13 = af::inverse(-U + V) * (U + V);
	af::array X = matpow(r13, d);
	return expn(mu) * X;
}
