#include "gradient.h"

int			num_Scale(int input, int from_min, int from_max, int to_min, int to_max)
{
	int		result;
	int		range;
	double	tmp;

	range = (from_max - from_min);

	tmp = input - from_min;
	tmp /= range;
	tmp *= (to_max - to_min);
	result = tmp + to_min;

	return result;
}

int blurr_pixel(int x,int y, gauss_matrix matrix, int x_bound, int y_bound)
{
	int x_low;
	int x_high;
	int y_low;
	int y_high;

	int i;
	int n;
	double total;

	x_low = MAX(x - matrix.w, 0);
	y_low = MAX(y - matrix.h, 0);
	x_high = MIN(x + matrix.w, x_bound);
	y_high = MIN(y + matrix.h, y_bound);

	total = 0;
	i = y_low;
	
	while(i < y_high)
	{
		n = x_low;
		while(n < x_high)
		{
			total += 1;
		}
	}
	return total / (matrix.w * matrix.h);
}

void blurr_texture(SDL_Rect area, gauss_matrix mat, SDL_Surface *surf)
{
	int x;
	int y;

	Uint32 pixel;
	SDT_RGBA color;

	x = area.x;
	y = area.y;
	while (y < area.h + area.y)
	{
		while (x < area.w + area.x)
		{
			y = 1;
			//Dont forget to check for oob pixels
			//Maybe blurr pixel function else this might be a very long function

		}
	}
}