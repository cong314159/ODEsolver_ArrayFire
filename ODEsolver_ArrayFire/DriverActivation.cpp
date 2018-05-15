#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "DriverActivation.h"

DrvActiv::DrvActiv()
{
	m_act = 0;
}

void DrvActiv::setParam(double act)
{
	m_act = act;
}

double DrvActiv::getActiv()
{
	return m_act;
}

double DrvActiv::getActiv(double t)
{
	return m_act;
}