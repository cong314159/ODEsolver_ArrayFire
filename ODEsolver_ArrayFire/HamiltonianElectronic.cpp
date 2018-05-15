#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "HamiltonianElectronic.h"
#include "constants_parameters_extern.h"

H_elect::H_elect() {}

af::array H_elect::getHe(ClockField & cf, DrvPolar & dp, DrvActiv & da, double t)
{
	double da_t = da.getActiv(t);
	double dp_t = dp.getPolar(t);
	double cf_t = cf.getField(t);

	double q0_drv = (1 - dp_t) * da_t * qe / 2;
	double q1_drv = (1 + dp_t) * da_t * qe / 2;
	double qn_drv = -da_t * qe;

	double Hclk_vector[] = { 0,0,0,0,1,0,0,0,0 };
	af::array Hclk = af::array(Ne, Ne, Hclk_vector);
	Hclk *= -a * cf_t / 2;

	double Hkin_vector[] = { 0,1,0,1,0,1,0,1,0 };
	af::array Hkin = af::array(Ne, Ne, Hkin_vector);
	Hkin *= -gamma;

	double partx = (double)1 / 4 / M_PI / a / 1e-9 / epsilon0;
	double part1a = (qn_drv - q0_drv - q1_drv) / sqrt((double)3 / 2);
	double part1b = q0_drv / sqrt((double)2);
	double part1c = q1_drv - qn_drv;
	double E1 = (part1a + part1b + part1c) * partx;
	double part0a = (qn_drv - q0_drv - q1_drv) / sqrt((double)3 / 2);
	double part0b = q1_drv / sqrt((double)2);
	double part0c = q0_drv - qn_drv;
	double E0 = (part0a + part0b + part0c) * partx;
	double Hnei_vector[] = { E0,0,0,0,0,0,0,0,E1 };
	af::array Hnei = af::array(Ne, Ne, Hnei_vector);

	af::array He = Hclk + Hkin + Hnei;

	return He;
}