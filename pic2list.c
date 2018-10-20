#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include <err.h>

int* pic2list(SDL_Surface* pic)
{
	int width = pic->w;
	int height = pic->h;
	int* list = malloc((width*height)*sizeof(int));
	Uint8 r, g ,b;
	Uint32 pixel;

	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			pixel = get_pixel(pic, i, j);
			SDL_GetRGB(pixel, pic->format, &r, &g, &b);

			if(r == 0)
				list[i + j] = 1;
			else
				list[i + j] = 0;
		}
	}
	return list;
}
