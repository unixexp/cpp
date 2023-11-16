BUILD_DIR = build
BUILD_LIB_DIR = $(BUILD_DIR)/lib
MAKE_BUILD_DIRS = test -d $(BUILD_DIR) || mkdir $(BUILD_DIR) && mkdir $(BUILD_LIB_DIR)
OBJS = $(BUILD_DIR)/main.o
OUT = $(BUILD_DIR)/main
CC = g++
FLAGS = -g -c -Wall
LFLAGS =
LIBS = -lsmartcontainer -LSmartLibrary/build/lib
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) $(LIBS)
	cp ./SmartLibrary/build/lib/libsmartcontainer.dylib $(BUILD_LIB_DIR)/
	install_name_tool -id @executable_path/lib/libsmartcontainer.dylib $(BUILD_LIB_DIR)/libsmartcontainer.dylib

$(BUILD_DIR)/main.o: main.cpp
	@$(MAKE_BUILD_DIRS)
	$(CC) $(FLAGS) -o $(BUILD_DIR)/main.o main.cpp -std=c++11

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)