Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp)
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
}


int blurr_pixel(int x,int y, gauss_matrix **matrix, int x_bound, int y_bound, )
{
	int x_low;
	int x_high;
	int y_low;
	int y_high;

	int i;
	int n;
	double total;

	x_low = max(x - m, 0);
	y_low = max(y - n, 0);
	x_high = min(x + m, x_bound);
	y_high = min(y + n, y_bound);

	total = 0;
	i = y_low;
	
	while(i < y_high)
	{
		n = x_low;
		while(n < x_high)
		{
			total += 
		}
	}

}

void blurr_texture(SDL_Rect area, gauss_matrix mat, SDL_Surface *surf,)
{
	int x;
	int y;

	Uint_32 pixel;
	SDT_RGBA color;

	x = area.x;
	y = area.y;
	while (y < area.h + area.y)
	{
		while (x < area.w + area.x)
		{
			//Dont forget to check for oob pixels
			//Maybe blurr pixel function else this might be a very long function

		}
	}
}