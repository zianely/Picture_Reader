#include <stdlib.h>
#include <gtk/gtk.h>
#include "init_matrix.h"

int** matx(GdkPixbuf* pixbuf)
{
	int W = gdk_pixbuf_get_width(pixbuf);
	int H = gdk_pixbuf_get_height(pixbuf);

	guchar* pixels = NULL;
	pixels = gdk_pixbuf_get_pixels(pixbuf);
	
	gint channel = 0;
	channel = gdk_pixbuf_get_n_channels(pixbuf);

	int size = W*H*channel; //size of pixels

	int** matrix = init_matrix(W, H);

	int larg = 0;
	int prof = 0;

	for(int i = 0; i <= size; i += W) //parcours des pixels
	{
		for(int j = 0; j <= W; j += channel)
		{
			if(pixels[j] == 0)//if pixel is white
			{
				continue;
			}
			else //if pixel is black
			{
				matrix[prof][larg] = 1;
			
			}
			larg += 1;
		}
		prof += 1;

	}
	return matrix;
}
