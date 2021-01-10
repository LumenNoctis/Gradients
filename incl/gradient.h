#ifndef GRADIENT_H
# define GRADIENT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "SDT.h"
# include "lerp.h"

# define GAUSS_X_DIST 5
# define GAUSS_Y_DIST 5

struct glerp
{
	int start;
	int end;

	double span_start;
	double span_end;
};

typedef struct	s_gradient
{
	int 			ncolors;
	struct	glerp 	*g_lerp;
}					t_gradient;

int *gradient(int from, int to, int ncolors);



#endif
