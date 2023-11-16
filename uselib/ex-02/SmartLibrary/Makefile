BUILD_DIR = build
BUILD_LIB_DIR = $(BUILD_DIR)/lib
MAKE_BUILD_DIRS = test -d $(BUILD_DIR) || mkdir $(BUILD_DIR) && \
					test -d $(BUILD_LIB_DIR) || mkdir $(BUILD_LIB_DIR)
OBJS = $(BUILD_DIR)/SmartContainer.o
CC = g++
FLAGS = -g -c -Wall
LFLAGS = 
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)

$(BUILD_DIR)/SmartContainer.o: SmartContainer.cpp
	@$(MAKE_BUILD_DIRS)
	$(CC) $(FLAGS) -o $(BUILD_DIR)/SmartContainer.o SmartContainer.cpp -std=c++11
	$(CC) -shared -o $(BUILD_LIB_DIR)/libsmartcontainer.so $(BUILD_DIR)/SmartContainer.o -std=c++11

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)