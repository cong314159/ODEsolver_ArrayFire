#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "PadeApprox_pkm.h"
#include "Factorial.h"
#include "MatrixPower.h"

af::array pkm(af::array & a, int km)
{
	af::array r = af::constant(0, a.dims(0), a.dims(1), c64);
	af::array ap = a;
	for (int j = 0; j <= km; j++)
	{
		r += (factorial(km + km - j) * factorial(km) / factorial(km + km) / factorial(km - j) / factorial(j)) * matpow(a, j);
		//af_print(r);
	}
	return r;
}
