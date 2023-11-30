LIB = ./lib
BUILD_DIR = build
OBJS = main.o
OUT = main
CC = g++
CFLAGS = -std=c++11 -g -Wall -I/usr/local/Cellar/glib/2.68.3/include/glib-2.0 -I/usr/local/Cellar/glib/2.68.3/lib/glib-2.0/include
LFLAGS = -g -L/usr/local/Cellar/glib/2.68.3/lib -lglib-2.0.0
# -g option enables debugging mode 
# -c flag generates object code for separate files

O = .o

all: prepare $(OBJS)
	@echo Build application
	@$(CC) $(OBJS) -o $(BUILD_DIR)/$(OUT) $(LFLAGS)

main.o: main.c
	@echo Compile $<
	@$(CC) $(CFLAGS) -c -o main.o $<

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)

prepare:
	@echo "Making build directory"
	test -d $(BUILD_DIR) || mkdir $(BUILD_DIR)
