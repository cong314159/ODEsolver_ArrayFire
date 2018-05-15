#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "DriverPolarization.h"

DrvPolar::DrvPolar()
{
	m_T = 0;
}

void DrvPolar::setParam(double T)
{
	m_T = T;
}

double DrvPolar::getPolar(double t)
{
	return sin(M_PI * 2 * t / m_T);
}