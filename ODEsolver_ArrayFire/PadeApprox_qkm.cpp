#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "PadeApprox_qkm.h"
#include "Factorial.h"
#include "MatrixPower.h"

af::array qkm(af::array & a, int km)
{
	af::array r = af::constant(0, a.dims(0), a.dims(1), c64);
	af::array an = -a;
	for (int j = 0; j <= km; j++)
	{
		r += (factorial(km + km - j) * factorial(km) / factorial(km + km) / factorial(km - j) / factorial(j)) * matpow(an, j);
		//af_print(r);
	}
	return r;
}
