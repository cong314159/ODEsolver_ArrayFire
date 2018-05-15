#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "MatrixPower.h"

af::array matpow(af::array & a, int p)
{
	if (p == 0)
	{
		return af::identity(a.dims(0), a.dims(1), f64);
	}
	else
	{
		int d = 2;
		af::array r = a;
		while (d <= p)
		{
			d *= 2;
			r = af::matmul(r, r);
		}
		return r = af::matmul( r, matpow(a, p - (d / 2)));
	}
}
