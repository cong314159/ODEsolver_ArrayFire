#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "ClockField.h"

ClockField::ClockField()
{
	m_T = 0;
	m_amp = 0;
}

void ClockField::setParam(double T, double amp)
{
	m_T = T;
	m_amp = amp;
}

double ClockField::getField(double t)
{
	return m_amp * cos(M_PI * 2 * t / m_T);
}