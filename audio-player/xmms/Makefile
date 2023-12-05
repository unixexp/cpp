O=.o

INSTALL_PREFIX=/usr/local
BIN_DIR=$(INSTALL_PREFIX)/bin
LIB_DIR=$(INSTALL_PREFIX)/lib/xmms
PLUGIN_DIR=$(LIB_DIR)/Plugins
PLUGIN_SUBS=Output Input Effect General Visualization
DPLUGIN_SUBS="\\\"Output\\\",\\\"Input\\\",\\\"Effect\\\",\\\"General\\\",\\\"Visualization\\\""

BUILD_DIR=build
OBJS=about$(O)
OUT=main
CC=gcc
CFLAGS=-g -Wall \
	-I../ \
	-I../libxmms \
	-I/usr/include/glib-2.0 \
	-I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
	-I/usr/include/gtk-2.0 \
	-I/usr/include/cairo \
	-I/usr/include/pango-1.0 \
	-I/usr/include/harfbuzz \
	-I/usr/lib/x86_64-linux-gnu/gtk-2.0/include \
	-I/usr/include/gdk-pixbuf-2.0 \
	-I/usr/include/atk-1.0 \
	-DPLUGIN_DIR=\"$(PLUGIN_DIR)\" -DPLUGINSUBS=\"$(DPLUGIN_SUBS)\"
LFLAGS=-g -L/usr/lib/x86_64-linux-gnu -lgtk-x11-2.0 -lgdk-x11-2.0 -lgobject-2.0 -lglib-2.0

all: prepare $(OBJS)
	@echo "$(CC) $(OBJS) -o $(BUILD_DIR)/$(OUT) $(LFLAGS)"
	$(CC) $(OBJS) -o $(BUILD_DIR)/$(OUT) $(LFLAGS)

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)

prepare:
	@test -d $(BUILD_DIR) || mkdir $(BUILD_DIR)

# Sources
about.o: about.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o about$(O) $<


