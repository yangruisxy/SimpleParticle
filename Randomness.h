#pragma once
#include <cstdlib>
#include <time.h>
static float RandF()
{
	return (float)(rand()) / (float)RAND_MAX;
}

static float RandF(float a, float b)
{
	return a + RandF() * (b - a);
}