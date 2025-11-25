#include <gtk/gtk.h>
#include "../include/scheduler.h"

static void on_run_clicked(GtkWidget *widget, gpointer data) {
    // Aquí iría la lógica para ejecutar el algoritmo seleccionado
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Simulation executed!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "CPU Scheduler Simulator");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *button = gtk_button_new_with_label("Run Simulation");
    g_signal_connect(button, "clicked", G_CALLBACK(on_run_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("org.cpu.scheduler", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
