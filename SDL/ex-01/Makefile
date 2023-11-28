OS = MacOS
LIBRARY = ../../_library_/$(OS)/SDL2

BUILD_DIR = build
BUILD_LIB_DIR = $(BUILD_DIR)/lib
MAKE_BUILD_DIRS = test -d $(BUILD_DIR) || mkdir $(BUILD_DIR) && mkdir $(BUILD_LIB_DIR)
OBJS = $(BUILD_DIR)/main.o
OUT = $(BUILD_DIR)/main
CXX = g++
CXXFLAGS = -g -c -Wall -I$(LIBRARY)/include
LDFLAGS = -L$(LIBRARY)/lib -lSDL2-2.0.0
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CXX) -g $(OBJS) -o $(OUT) $(LDFLAGS)

$(BUILD_DIR)/main.o: main.cpp
	@$(MAKE_BUILD_DIRS)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/main.o main.cpp -std=c++11

clean:
	rm -Rf $(BUILD_DIR)
	rm -f $(OBJS) $(OUT)