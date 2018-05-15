#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "HamiltonianVibron.h"
#include "constants_parameters_extern.h"

H_vibron::H_vibron() {}

void H_vibron::calculation()
{
	// the making of annihilation and creation operators
	/*af::dim4 dimension = af::dim4(Nv-1);
	af::array seq = af::sqrt(af::range(dimension, -1, f64) + 1);*/

	af::array anni = sqrt(diag(af::seq(1, 20), 1, false));
	af::array annid = af::transpose(anni);
	// the making of vibrionic Hamiltonian
	af::array ada = af::matmul(annid, anni);
	Hv = hbw * (ada + (af::identity(Nv, Nv, f64) / 2));
	//af_print(Hv);
}

af::array H_vibron::getHv()
{
	return Hv;
}