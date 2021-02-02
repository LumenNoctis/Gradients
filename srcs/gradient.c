#include "../incl/gradient.h"
#include "../incl/lerp.h"

t_gradient create_gradient()
{
	int i;
	t_gradient grad;

	grad.ncolors = 1;

	grad.g_lerp = calloc(grad.ncolors, sizeof(*grad.g_lerp));

	grad.g_lerp[0].start = 0xFF0000FF;
	grad.g_lerp[0].end = 0xFFFFFFFF;
	grad.g_lerp[0].span_start = 0;
	grad.g_lerp[0].span_end = 1;

	grad.g_lerp[1].start = 0x00FF00FF;
	grad.g_lerp[1].end = 0xFF00FFFF;
	grad.g_lerp[1].span_start = .200;
	grad.g_lerp[1].span_end = .410;

	//grad.g_lerp[2].start = 0xFF00FFFF;
	//grad.g_lerp[2].end = 0xFFFF00FF;
	//grad.g_lerp[2].span_start = .400;
	//grad.g_lerp[2].span_end = 1;

	return grad;
}

SDL_Texture *render_grad_texture(t_gradient grad, int ncolors, int h, int w)
{
	int p_start;
	int p_end;
	int scale;
	int col;
	int m;
	int i;
	int t;

	SDT_RGBA color;

	SDL_Rect		rect;
	SDL_Texture 	*result;
	SDL_Surface 	*surf;
	SDL_Renderer 	*renderer;

	gauss_curve curve;
	gauss_matrix mat;


	i = 0;
	printf("called\n");
	if (ncolors <= 0)
		m = 1;
	else
		m = w / ncolors;

	rect.h = h;
	rect.w = m;
	rect.y = 0;
	rect.x = 0;
	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	renderer = SDT_GetScene()->renderer;


	curve.width = 3;
	curve.center = 0;
	curve.height = 5;

	color.data.a = 255;

	// create_gauss_matrix(curve, GAUSS_X_DIST, GAUSS_Y_DIST);
	printf("Creating gradient\n");
	while (i < grad.ncolors)
	{
		p_start = grad.g_lerp[i].span_start * w;
		p_end = grad.g_lerp[i].span_end * w;
		while (p_end >= rect.x)
		{
			scale = num_Scale(rect.x, p_start, p_end, 0, SMOOTHNESS);
			if (scale == 0)
				t = 0;
			else
				t = scale;
			color.data.r = lerp(
						(int)((SDT_RGBA)grad.g_lerp[i].start).data.r,
						(int)((SDT_RGBA)grad.g_lerp[i].end).data.r,
						t, SMOOTHNESS);
			color.data.g = lerp(
						(int)((SDT_RGBA)grad.g_lerp[i].start).data.g,
						(int)((SDT_RGBA)grad.g_lerp[i].end).data.g,
						t,SMOOTHNESS);
			color.data.b = lerp(
						(int)((SDT_RGBA)grad.g_lerp[i].start).data.b,
						(int)((SDT_RGBA)grad.g_lerp[i].end).data.b,
						t, SMOOTHNESS);
			SDL_FillRect(surf, &rect, color.color);
			rect.x += m;
		}
		i++;
	}
	printf("Done\n");
	result = SDL_CreateTextureFromSurface(renderer, surf);
	// SDL_FreeSurface(surf);
	//use Gauss here
	return result;
}