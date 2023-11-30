#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    gchar *filename;
    filename = g_strconcat(g_get_home_dir(), "/.xmms", NULL);
    g_free(filename);

}