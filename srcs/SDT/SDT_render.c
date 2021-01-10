#include "../../incl/SDT.h"
#include "../../incl/gradient.h"

SDL_texture *render_grad_texture(t_gradient *grad, int ncolors, int h, int w)
{
	int m;
	int i;
	int col;

	SDT_RGBA color;

	SDL_Rect		rect;
	SDL_Texture 	*tex;
	SDL_Surface 	*surf;
	SDL_Renderer 	*renderer;

	gauss_curve curve;
	gauss_matrix mat;


	i = 0;
	if (ncolors <= 0)
		m = w
	else
		m = w / ncolors;

	rect.h = h;
	rect.w = w / ncolors;
	rect.y = 0;
	rect.x = 0;
	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	renderer = SDT_GetScene()->renderer;


	curve.width = 3;
	curve.center = 0;
	curve.height = 5;

	gauss_matrix(curve, GAUSS_X_DIST, GAUSS_Y_DIST);

	while (i < grad.ncolors)
	{
		p_start = grad[i].span_start * w;
		p_end = grad[i].span_end * w;
		while (p_end >= rect.x)
		{
			t = 
			color.r = lerp(
						((SDT_RGBA)grad.grad_lerp[i].start).data.r,
						((SDT_RGBA)grad.grad_lerp[i].end).data.r,
						p_end - rect.x);
			
			SDL_FillRect(surf, &rect, color);
			rect.x += m;
		}
		i++;
	}
	result = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);

	return result;
}