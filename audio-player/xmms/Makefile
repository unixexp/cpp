O=.o

INSTALL_PREFIX=/usr/local
BIN_DIR=$(INSTALL_PREFIX)/bin
LIB_DIR=$(INSTALL_PREFIX)/lib/xmms
PLUGIN_DIR=$(LIB_DIR)/Plugins
PLUGIN_SUBS=Output Input Effect General Visualization
DPLUGIN_SUBS="\\\"Output\\\",\\\"Input\\\",\\\"Effect\\\",\\\"General\\\",\\\"Visualization\\\""

BUILD_DIR=build
OBJS=main$(O) pluginenum$(O)
OUT=main
CC=gcc
CFLAGS=-g -Wall -I/usr/local/Cellar/glib/2.68.3/include/glib-2.0 -I/usr/local/Cellar/glib/2.68.3/include/glib-2.0/glib \
	-I/usr/local/Cellar/glib/2.68.3/lib/glib-2.0/include -DPLUGIN_DIR=\"$(PLUGIN_DIR)\" -DPLUGINSUBS=\"$(DPLUGIN_SUBS)\"
LFLAGS=-g -L/usr/local/Cellar/glib/2.68.3/lib -lglib-2.0.0
# -g option enables debugging mode
# -c flag generates object code for separate files

all: prepare $(OBJS)
	$(CC) $(OBJS) -o $(BUILD_DIR)/$(OUT) $(LFLAGS)

main.o: main.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o main$(O) $<

pluginenum.o: pluginenum.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o pluginenum$(O) $<

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)

prepare:
	@test -d $(BUILD_DIR) || mkdir $(BUILD_DIR)
