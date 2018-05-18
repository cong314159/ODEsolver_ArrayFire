#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "getValue.h"

af::cdouble getValue(af::array a)
{
	af::cdouble * a_host = a.host<af::cdouble>();
	af::cdouble r = a_host[0];
	af::freeHost(a_host);
	return r;
}
