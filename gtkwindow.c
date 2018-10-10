#include <stdlib.h>
#include <gtk/gtk.h>
//#include "fonction de thibault.h"
 
int main(int argc, char **argv)
{
	
	GtkWidget* mainwindow = NULL;			//declaration d'un pointeur sur GTKWidget
	GError* error = NULL;
	GdkPixbuf* pix = gdk_pixbuf_new_from_file("texte_test.png", &error);
	gint height;
	gint width;
	GtkWidget* image;

	/* Initialisation de GTK+ */
	gtk_init(&argc, &argv);


	/* Creation de la fenetre */
	mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(mainwindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);


	/* Personnalisation de la fenetre */
	gtk_window_set_title (GTK_WINDOW(mainwindow), "Picture Reader");
	gtk_window_set_default_size(GTK_WINDOW(mainwindow), 1900, 1000);
	if (pix == NULL)
	{
	    	g_printerr ("Error loading file: #%d %s\n", error->code, error->message);
    		g_error_free (error);
    		exit (1);
	}

	image = gtk_image_new_from_pixbuf(pix);
	gtk_container_add(GTK_CONTAINER (mainwindow), image);

	/* Recup' infos fenetre */
	//title = gtk_window_get_title(GTK_WINDOW(mainwindow));
	//gtk_window_get_default_size(GTK_WINDOW(mainwindow), &width, &height);
	guchar* pixels = gdk_pixbuf_get_pixels(pix);

	//fonction de thibault(pixels)
	//reseau de neurone

	/* Affichage de la fenetre */
	gtk_widget_show(image);
	gtk_widget_show(mainwindow);
	gtk_main();


	return EXIT_SUCCESS;
}
