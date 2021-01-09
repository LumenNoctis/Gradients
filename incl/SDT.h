#ifndef SDT_H
# define SDT_H


# include <stdbool.h>

# include "SDT_structs.h"

void        SDT_Update();

void 		render_gradient(int ncolors);

SDT_Scene   *SDT_GetScene();


void        SDT_RenderLoop();
void        SDT_EventsLoop();
#endif