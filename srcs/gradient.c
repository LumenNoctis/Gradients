#include "../incl/gradient.h"
#include "../incl/lerp.h"

int sort_colors(const void *a,const void *b)
{
	Grad_data *a_data;
	Grad_data *b_data;

	a_data = (Grad_data*)a;
	b_data = (Grad_data*)b;

	if (a_data->location > b_data->location)
		return 1;
	return -1;
}

Gradient create_gradient(Grad_data *data, int ncolors)
{
	int i;
	Gradient grad;


	qsort(data, ncolors, sizeof(*data), sort_colors);
	grad.colors = data;
	grad.ncolors = ncolors;

	return grad;
}

int GradColor_Get(int t, Gradient grad, int i)
{
	int	r;
	int	g;
	int	b;


	r = lerp(
				(int)((grad.colors[i].color >> 24) & 0xFF),
				(int)((grad.colors[i + 1].color >> 24)& 0xFF),
				t, SMOOTHNESS) & 0xFF;
	g = lerp(
				(int)((grad.colors[i].color >> 16) & 0xFF),
				(int)((grad.colors[i + 1].color >> 16) & 0xFF),
				t,SMOOTHNESS) & 0xFF;
	b = lerp(
				(int)((grad.colors[i].color >> 8) & 0xFF),
				(int)((grad.colors[i + 1].color >> 8) & 0xFF),
				t, SMOOTHNESS) & 0xFF;
	return (r << 24) | (g << 16) | (b << 8);
} 
SDL_Texture *render_grad_texture(Gradient grad, int amount, int h, int w)
{
	int p_start;
	int p_end;
	int scale;
	int col;
	int m;
	int i;
	int t;

	Uint32 			converted_color;
	
	
	SDL_Rect		rect;
	SDL_Texture 	*result;
	SDL_Surface 	*surf;
	SDL_Renderer 	*renderer;

	gauss_curve curve;
	gauss_matrix mat;


	i = 0;
	// Sets the step amount, if <= 0 , display 1 color per pixel in screen width
	if (amount <= 0)
		m = 1;
	else
		m = w / amount;

	rect.h = h / 2;
	rect.w = m;
	rect.y = 0;
	rect.x = 0;
	// Using surface for more speed
	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	renderer = SDT_GetScene()->renderer;

	// Gaussian blurr info
	//curve.width = 3;
	//curve.center = 0;
	//curve.height = 5;
	// create_gauss_matrix(curve, GAUSS_X_DIST, GAUSS_Y_DIST);

	while (i + 1 < grad.ncolors)
	{
		p_start = grad.colors[i].location * w;
		p_end = grad.colors[i + 1].location * w;
		while (p_end >= rect.x)
		{
			t = num_Scale(rect.x, p_start, p_end, 0, SMOOTHNESS);
			converted_color = GradColor_Get(t, grad, i);
			converted_color = SDL_MapRGBA(surf->format,
										converted_color >> 24,
										converted_color >> 16,
										converted_color >>  8,
										255
										);
			//SDL_Log("Converted color %d \n", converted_color);
			SDL_FillRect(surf, &rect, converted_color);
			rect.x += m;
		}
		i++;
	}
	result = SDL_CreateTextureFromSurface(renderer, surf);
	return result;
}

Uint32 *GradArray_Get(int amount, Gradient grad)
{
	int scale;
	int start;
	int end;
	int n;
	int i;
	int t;

	double m;
	double pos;
	Uint32 *array;
	Uint32 	color;


	i = 0;
	array = calloc(amount, sizeof(*array));
	if (amount <= 0)
		return NULL;
	else
		m = (double)1 / amount;

	pos = 0;
	n = 0;
	while (i + 1 < grad.ncolors)
	{
		start = grad.colors[i + 0].location;
		end	= grad.colors[i + 1].location;
		while (end >= pos)
		{
			if (n >= amount)
				break ;
			t = num_Scale(pos * 100, start * 100, end * 100, 0, SMOOTHNESS);
			color = GradColor_Get(t, grad, i);
			pos += m;
			array[n] = color;
			n++;
		}
		i++;
	}
	return array;
}