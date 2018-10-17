#include <stdio.h>
#include <gtk/gtk.h>
#include "init_matrix.h"
#include "printmatrix.h"
#include "pixbuf2binmtx.h"


int main(int argc, char **argv)
{
	/* Initialisation de Gtk */

	gtk_init(&argc, &argv);

	/*-----------------------*/

	GError* error = NULL;
	//GtkWidget* mainwindow = NULL;

	GdkPixbuf* pix = gdk_pixbuf_new_from_file("10x10.png", &error);

	int w = gdk_pixbuf_get_width(pix);
	int h = gdk_pixbuf_get_height(pix);

	int** test = pixbuf2binmtx(pix);

	printmatrix(h, w, (int**) test);

	return 0;
}
