#include "../../incl/SDT.h"
#include "../../incl/gradient.h"


static void SDT_Exit(void)
{
	SDL_DestroyWindow(SDT_GetScene()->window);

	SDL_Quit();
}

void SDT_Init(SDT_Scene *scene)
{
	SDL_Window *window;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
				WIN_NAME,
				WIN_X, WIN_Y,
				WIN_H, WIN_W,
				SDL_WINDOW_SHOWN
		);
	scene->window = window;
	scene->renderer = SDL_CreateRenderer(window, -1, 0);
	atexit(SDT_Exit);
}

static void SDT_SetScene(SDT_Scene *scene)
{
	Grad_data *grad;
	int ncolors;

	ncolors = 2;
	grad = calloc(ncolors, sizeof(*grad));
	grad[0].color = 0x00000000;
	grad[1].color = 0xFFFFFFFF;
	grad[0].location = 0;
	grad[1].location = 1;
	SDT_Init(scene);
	scene->tex = render_grad_texture(create_gradient(grad, ncolors), NCOLORS, WIN_H, WIN_W);
}

SDT_Scene *SDT_GetScene()
{
	static SDT_Scene scene;

	if (scene.window == NULL)
		SDT_SetScene(&scene);
	return &scene;
}