#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "kron.h"
#include "constants_parameters_extern.h"

af::array kron(af::array& a1, af::array& a2)
{
	af::array a1_flat = af::flat(a1);
	af::array a2_flat = af::flat(a2);

	//af_print(a1);
	//af_print(a1_flat);

	af::array data_unformed = af::matmul(a1_flat, a2_flat.T());

	af::array data_dimed = af::moddims(data_unformed.T(), a2.dims(0), a2.dims(1), a1.dims(0), a1.dims(1));

	af::array data_reordered = af::reorder(data_dimed, 0, 2, 1, 3);

	af::array kron_prod = af::moddims(data_reordered, a1.dims(0) * a2.dims(0), a1.dims(1) * a2.dims(1));

	//af_print(result);

	return kron_prod;
}