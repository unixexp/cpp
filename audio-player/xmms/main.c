#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <getopt.h>
#include <signal.h>
#include <ctype.h>
#include <fcntl.h>
#ifdef HAVE_SCHED_H
# include <sched.h>
#elif defined HAVE_SYS_SCHED_H
# include <sys/sched.h>
#endif

#include "xmms.h"

int main() {

    gchar *filename;
    filename = g_strconcat(g_get_home_dir(), "/.xmms", NULL);
    printf("%s", filename);
    g_free(filename);

}