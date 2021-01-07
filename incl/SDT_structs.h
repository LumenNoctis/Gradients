#ifndef SDT_DEF_H
# define SDT_DEF_H

# define WIN_NAME "Default"
# define WIN_X 0
# define WIN_Y 0
# define WIN_H 500
# define WIN_W 500
# define BACKGROUND 0xFFFFFFFF

# if WIN_H == 0 || WIN_W == 0
#	error "Undefined window size in SDT_structs.h"
#endif

typedef union       SDT_RGBA
{
	uint32_t		color;
	struct {
		uint8_t 	r;
		uint8_t 	g;
		uint8_t 	b;
		uint8_t 	a;
	}				color_data;
}					SDT_RGBA;

typedef struct
{
    SDL_Window      *window;
    SDL_Renderer    *renderer;
}               SDT_Scene;

# endif