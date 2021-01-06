#include "gradient.h"

int lerp(int v0, int v1, double t)
{
	return v0 + t * (v1 - v0);
}

double lerpf(double v0, double v1, double t)
{
	return (1 - t ) * v0 + t * (v1 - v0);
}

// int	bilinear(int x[4], int y[4], double t)
// {

// }
