#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "PadeApprox.h"
#include "MatrixPower.h"
#include "PadeApprox_pkm.h"
#include "PadeApprox_qkm.h"

af::array padeApprox(af::array & a, int m)
{
	return pkm(a, m) * af::inverse(qkm(a, m));
}
