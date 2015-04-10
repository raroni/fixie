NAME = Flowstone

CC = clang++
CPP_CFLAGS = -Wall -std=gnu++11 -stdlib=libc++ -ferror-limit=1

BUILD_DIR = ./Build

TEST_SOURCES =\
	Library/Source/Trig.cpp\
	Library/Source/Util.cpp\
	Library/Source/Vector3.cpp\
	Library/Source/Matrix4.cpp\
	Library/Source/Quaternion.cpp\
	Test/main.cpp

TEST_HEADER_DIRS =\
	-ILibrary/Include\

TEST_OBJECTS = $(patsubst %.cpp,$(BUILD_DIR)/Objects/Test/%.o,$(TEST_SOURCES))

TEST_EXECUTABLE_PATH = $(BUILD_DIR)/Test

test: $(TEST_EXECUTABLE_PATH)
	$(TEST_EXECUTABLE_PATH)

$(TEST_EXECUTABLE_PATH): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_HEADER_DIRS) $(TEST_OBJECTS) -o $@

$(BUILD_DIR)/Objects/Test/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CPP_CFLAGS) $(TEST_HEADER_DIRS) $< -c -o $@

clean:
	rm -rf ./Build
