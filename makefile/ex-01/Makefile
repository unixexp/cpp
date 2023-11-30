LIB = ./lib
BUILD_DIR = build
OBJS = $(LIB)/vars.o main.o
OUT = main
CC = g++
CFLAGS = -g -Wall -I$(LIB)
LFLAGS = -g
# -g option enables debugging mode 
# -c flag generates object code for separate files

O = .o

all: prepare $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o main.o main.cpp -std=c++11

$(LIB)/vars.o: $(LIB)/vars.cpp
	$(CC) $(CFLAGS) -c -o $(LIB)/vars.o $(LIB)/vars.cpp -std=c++11

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)

prepare:
	@echo "Prepare actions no implemented yet"