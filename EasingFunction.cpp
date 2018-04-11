#include "EasingFunction.h"
#define _USE_MATH_DEFINES
#include <cmath>
//From https://github.com/warrenm/AHEasing/blob/master/AHEasing/easing.c
//return the progress, Input is the fraction

float LinearInterpolation(float p)
{
	return p;
}

float QuadraticEaseInOut(float p)
{
	if (p < 0.5)
	{
		return 2 * p * p;
	}
	else
	{
		return (-2 * p * p) + (4 * p) - 1;
	}
}

float CubicEaseInOut(float p)
{
	if (p < 0.5)
	{
		return 4 * p * p *p;
	}
	else
	{
		float f = ((2 * p) - 2);
		return 0.5 * f * f * f + 1;
	}
}

float SineEaseInOut(float p)
{
	return 0.5 * (1 - cos(p * M_PI));
}

float CircularEaseInOut(float p)
{
	if (p < 0.5)
	{
		return 0.5 * (1 - sqrt(1 - 4 * (p * p)));
	}
	else
	{
		return 0.5 * (sqrt(-((2 * p) - 3) * ((2 * p) - 1)) + 1);
	}
}