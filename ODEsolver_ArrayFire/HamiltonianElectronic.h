#pragma once

#include "ClockField.h"
#include "DriverPolarization.h"
#include "DriverActivation.h"

class H_elect
{
public:
	H_elect();
    af::array getHe(ClockField & cf, DrvPolar & dp, DrvActiv & da, double t);
};