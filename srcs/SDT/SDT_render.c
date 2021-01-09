#include "../../incl/SDT.h"
#include "../../incl/gradient.h"

void render_gradient(int ncolors)
{
	int w;
	int i;
	int * grad;

	SDT_RGBA col;
	SDL_Rect div;
	SDL_Surface *surf;
	SDL_Renderer *renderer;

	surf = 
	renderer = SDT_GetScene()->renderer;
	grad = gradient(0, 255, ncolors);
	div.x = 0;
	div.y = 0;
	div.h = WIN_H;
	div.w = w;

	i = 0;
	w = WIN_W / ncolors;

	while (i < ncolors)
	{
		col.color = grad[i];
		SDL_SetRenderDrawColor(renderer, 0, grad[i], 0, 255);
		SDL_RenderFillRect(renderer, &div);
		SDL_Delay(10);
		i++;
		div.x += w;
	}
	// exit(0);
}