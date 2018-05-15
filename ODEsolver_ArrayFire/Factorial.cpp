#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

#include "Factorial.h"

long long factorial(int a)
{
	if (a == 0)
	{
		return 1;
	}
	else
	{
		return a * (factorial(a - 1));
	}
}
