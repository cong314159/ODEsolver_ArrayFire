#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "expn.h"

af::cdouble expn(af::cdouble a)
{
	af::array a_array = af::array(1, 1, c64);
	a_array(0, 0) = a;
	af::array r_array = af::exp(a_array);

	af::cdouble * r_host = r_array.host<af::cdouble>();
	af::cdouble r = r_host[0];
	af::freeHost(r_host); // this step is a must
	return r;
}
