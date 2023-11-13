BUILD_DIR = build
BUILD_LIB_DIR = $(BUILD_DIR)/lib
MAKE_BUILD_DIRS = test -d $(BUILD_DIR) || mkdir $(BUILD_DIR) && \
					test -d $(BUILD_LIB_DIR) || mkdir $(BUILD_LIB_DIR)
OBJS = $(BUILD_DIR)/main.o
OUT = $(BUILD_DIR)/main
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(BUILD_DIR)/main.o: main.cpp
	@$(MAKE_BUILD_DIRS)
	$(CC) $(FLAGS) -o $(BUILD_DIR)/main.o main.cpp -std=c++11


clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)