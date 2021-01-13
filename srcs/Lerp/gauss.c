#include "lerp.h"
#include <stdio.h>

gauss_matrix *create_gauss_matrix(gauss_curve curve, int x_distance, int y_distance)
{
	int		i;
	int		n;
	int		x;
	int		y;

	double	h;	
	double	div;
	double	distance;

	gauss_matrix *mat;
	
	mat = calloc(1, sizeof(*mat));
	mat->w = y_distance * 2 + 1;
	mat->h = x_distance * 2 + 1;
	mat->matrix = calloc(mat->h * 2 + 1, sizeof(int *));

	i = 0;
	y = -y_distance;
	div = 2 * curve.width * curve.width;

	while (y <= y_distance)
	{
		n = 0;
		x = -x_distance;
		h = curve.height / curve.width;
		mat->matrix[i] = calloc(x_distance * 2 + 1, sizeof(int *));
		while (x <= x_distance)
		{
			distance = pow(curve.center - (abs(x) + abs(y)), 2);
			distance /= div;
			mat->matrix[i][n] = h * exp(distance * -1);
			n++;
			x++;
		}
		h += curve.height / curve.width;
		i++;
		y++;
	}
	return mat;
}
