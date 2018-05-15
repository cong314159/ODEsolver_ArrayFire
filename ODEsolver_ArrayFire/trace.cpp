#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "trace.h"

af::cdouble trace(af::array & a)
{
	if (a.dims(0) != a.dims(1))
	{
		return af::cdouble(0,0);
	}
	else
	{
		af::array tr_array = af::array(1, 1, c64);
		tr_array(0, 0) = 0;
		for (int id = 0; id < a.dims(0); id++)
		{
			//af_print(a(id, id));
			tr_array += a(id, id);
		}
		
		af::cdouble * tr_array_host = tr_array.host<af::cdouble>();
		af::cdouble tr = tr_array_host[0];
		af::freeHost(tr_array_host);

		return tr;
	}
}
