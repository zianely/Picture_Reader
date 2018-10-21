#include <gtk/gtk.h>
// gcc $(pkg-config --libs --cflags gtk+-2.0) ocr_ui.c -o ocr



void destroy( GtkWidget *widget,
              gpointer   data )
{
    gtk_main_quit();
}




gint delete_event( GtkWidget *widget,
                   GdkEvent  *event,
                   gpointer   data )
{
    g_print ("delete event occurred\n");
    return(TRUE);
}

void open_dialog(GtkWidget *button,gpointer window)
{
    GtkWidget *dialog;
    dialog=gtk_file_chooser_dialog_new("Choose a file",GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
    gtk_widget_show_all(dialog);
    gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
    if(resp == GTK_RESPONSE_OK)
        g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
    else
        g_print("You pressed Cancel\n");
    gtk_widget_destroy(dialog);
}



int main( int   argc,
          char *argv[] )
{
 /* GtkWidget is the storage type for widgets */
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

 /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    button = gtk_button_new_with_label("Choose a file");
    g_signal_connect(button, "clicked", GTK_SIGNAL_FUNC(open_dialog), window);

 /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_container_add(GTK_CONTAINER(window), button);

    // gtk_widget_set_size_request(button,1,1);
    gtk_widget_show_all (window);
    gtk_main ();
}
