OBJS = main.o lib/Dollars.o
HEADER = lib/Dollars.h
OUT	= main
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

# create/compile the individual files >>separately<<
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

lib/Dollars.o: lib/Dollars.cpp
	$(CC) $(FLAGS) -o lib/Dollars.o lib/Dollars.cpp -std=c++11


# clean house
clean:
	rm -f $(OBJS) $(OUT)