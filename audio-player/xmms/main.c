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

Config cfg;
GList *disabled_iplugins = NULL;

int main() {

    // printf("PLUGIN_DIR=%s\n", PLUGIN_DIR);
    // printf("PLUGINSUBS=%s", PLUGINSUBS);
    // init_plugins();

}
