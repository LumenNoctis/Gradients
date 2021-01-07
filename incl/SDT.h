#ifndef SDT_H
# define SDT_H

# include <SDL2/SDL.h>
# include <stdbool.h>

# include "SDT_structs.h"

void        SDT_Update();

SDT_Scene   *SDT_GetScene();


void        SDT_RenderLoop();
void        SDT_EventsLoop();
#endif