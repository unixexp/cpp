OBJS = main.o
OUT = main
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUT)