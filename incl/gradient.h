#ifndef GRADIENT_H
# define GRADIENT_H

# include <stdio.h>
# include <stdlib.h>

# include <math.h>
# include "SDT.h"
# include "lerp.h"

# define GAUSS_X_DIST 5
# define GAUSS_Y_DIST 5
# define SMOOTHNESS 100 //100 is default, this is the number of colors in a full gradient
# define NCOLORS 	21 // Nuber of colors in the gradient 0 for full gradient -however many colors the screen can fit-

# define MAX(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

# define MIN(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

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

t_gradient	create_gradient();
SDL_Texture *render_grad_texture(t_gradient grad, int ncolors, int h, int w);

int			num_Scale(int input, int from_min, int from_max, int to_min, int to_max);
int			blurr_pixel(int x,int y, gauss_matrix matrix, int x_bound, int y_bound);
void		blurr_texture(SDL_Rect area, gauss_matrix mat, SDL_Surface *surf);

#endif
