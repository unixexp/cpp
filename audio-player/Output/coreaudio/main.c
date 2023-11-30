#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    gchar *filename;
    filename = g_strconcat(g_get_home_dir(), "/.xmms", NULL);
    printf("%s", filename);
    g_free(filename);

}