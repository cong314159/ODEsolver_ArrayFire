#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "HamiltonianCoupling.h"
#include "constants_parameters_extern.h"
#include "kron.h"

H_coupling::H_coupling() {}

void H_coupling::calculation()
{
	// the making of annihilation and creation operators
	af::dim4 dimension = af::dim4(Nv - 1);
	af::array seq = af::sqrt(af::range(dimension, -1, f64) + 1);
	af::array anni = diag(seq, 1, false);
	af::array annid = af::transpose(anni);
	// the making of combined vibrionic system
	double g_ev = sqrt(2 * m * omega * omega * lambda / 1000);
	af::array X = sqrt(hbar_eVs / 2 / m / omega) * (anni + annid);

	double sigz_vector[] = { -1,0,0,0,0,0,0,0,1 };
	af::array sigz = af::array(3, 3, sigz_vector);

	double test_vector[] = { 1,1,1,1,1,1,1,1,1 };
	af::array test = af::array(3, 3, test_vector);

	Hev = kron(sigz, X) * g_ev / 2;

	//af_print(Hev);

	//std::cout << g_ev << std::endl;
}

af::array H_coupling::getHev()
{
	return Hev;
}