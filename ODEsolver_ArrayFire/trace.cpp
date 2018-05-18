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
		std::cout << "attempting to trace a non square matrix" << std::endl;
		return 0;
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

		af::cdouble * tr_host = tr_array.host<af::cdouble>();
		af::cdouble tr = tr_host[0];
		af::freeHost(tr_host); // this step is a must

		return tr;
	}
}
