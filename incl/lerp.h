#ifndef LERP_H
# define LERP_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct 	s_gauss_curve
{
	int			width;
	int			center;
	int			height; 		
}				gauss_curve;

typedef struct s_gauss_mat
{
	int 		**matrix;
	int			w;
	int			h;
}				gauss_matrix;

int		lerp(int v0, int v1, double t, int resolution);

double	lerpf(double v0, double v1, double t);

int		gauss(gauss_curve *curve, int **area, int a_width, int a_height);

gauss_matrix *create_gauss_matrix(gauss_curve curve, int x_distance, int y_distance);

#endif