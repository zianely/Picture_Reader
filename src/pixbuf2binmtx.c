#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "init_matrix.h"
#include "printmatrix.h"
#include "printarray.h"

int** pixbuf2binmtx(GdkPixbuf* pixbuf)
{
	/*picture size*/

	int W = gdk_pixbuf_get_width(pixbuf);
	int H = gdk_pixbuf_get_height(pixbuf);

	/*------------*/

	guchar* pixels = NULL;
	pixels = gdk_pixbuf_get_pixels(pixbuf); //liste des pixels du pixbuf

	gint channel = 0;
	channel = gdk_pixbuf_get_n_channels(pixbuf);

	int size = W*H*channel; //size of pixels

	/*print test*/

	printarray(pixels, size);

	/*----------*/

	int** matrix = init_matrix(W, H); // matrice resultante

	int larg = 0;
	int prof = 0;

	for(int i = 0; i < size; i += W) //parcours des pixels -> lignes par lignes
	{
		for(int j = 0; j < W; j += channel) // channels par channels sur une ligne
		{
			if(pixels[i + j] == 255)//if pixel is white
			{
				matrix[larg][prof] = 0;
			}
			else //if pixel is black
			{
				matrix[larg][prof] = 1;		
			}
			larg += 1;
		}
		prof += 1;
		larg = 0;
	}

	return matrix;
}
