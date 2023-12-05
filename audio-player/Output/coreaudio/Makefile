O=.o

INSTALL_PREFIX=/usr/local
BIN_DIR=$(INSTALL_PREFIX)/bin
LIB_DIR=$(INSTALL_PREFIX)/lib/xmms

BUILD_DIR=build
OBJS=init$(O) about$(O) configure$(O) audio$(O) coreaudio$(O)
OUT=libcoreaudio.so
CC=gcc
CFLAGS=-g -fPIC -Wall -I../../ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LFLAGS=-g -shared -L/usr/lib/x86_64-linux-gnu -lglib-2.0

all: prepare $(OBJS)
	$(CC) $(OBJS) -o $(BUILD_DIR)/$(OUT) $(LFLAGS)

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)

prepare:
	@test -d $(BUILD_DIR) || mkdir $(BUILD_DIR)

# Sources
init.o: init.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o init$(O) $<

about.o: about.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o about$(O) $<

configure.o: configure.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o configure$(O) $<

audio.o: audio.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o audio$(O) $<

coreaudio.o: coreaudio.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o coreaudio$(O) $<

