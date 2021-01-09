#ifndef LERP_H
# define LERP_H

typedef struct 	s_gauss_curve
{
	int			height; 		
	int			width;
	int			center;
}				gauss_curve;

int lerp(int v0, int v1, double t);

double lerpf(double v0, double v1, double t);

int gauss(gauss_curve *curve, int **area, int a_width, int a_height);

#endif