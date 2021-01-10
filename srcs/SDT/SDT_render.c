#include "../../incl/SDT.h"
#include "../../incl/gradient.h"

SDL_texture *render_grad_texture(t_gradient *grad, int ncolors, int h, int w)
{
	int m;
	int i;
	int col;
	int t;

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
	rect.x = m;
	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	renderer = SDT_GetScene()->renderer;


	curve.width = 3;
	curve.center = 0;
	curve.height = 5;

	color.a = 255;

	gauss_matrix(curve, GAUSS_X_DIST, GAUSS_Y_DIST);

	while (i < grad.ncolors)
	{
		p_start = grad[i].span_start * w;
		p_end = grad[i].span_end * w;
		while (p_end >= rect.x)
		{
			t = 100/ num_Scale(rect.x, p_start, p_end, grad.g_lerp[i].start, grad.g_lerp[i].end)//Scale position from span to start-end, and divide 100 by it
			color.r = lerp(
						((SDT_RGBA)grad.g_lerp[i].start).data.r,
						((SDT_RGBA)grad.g_lerp[i].end).data.r,
						t);
			color.g = lerp(
						((SDT_RGBA)grad.g_lerp[i].start).data.r,
						((SDT_RGBA)grad.g_lerp[i].end).data.r,
						t);
			color.g = lerp(
						((SDT_RGBA)grad.g_lerp[i].start).data.r,
						((SDT_RGBA)grad.g_lerp[i].end).data.r,
						t);
			//Copy paste for all colors
			SDL_FillRect(surf, &rect, color); //Color here might need to be created wth SDL func, see doc
			rect.x += m;
		}
		i++;
	}
	result = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	//Add Blurr here
	return result;
}