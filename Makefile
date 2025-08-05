CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread
INCLUDES = -Iinclude
SRC = src/main.cpp src/file_search.cpp
TARGET = file_search

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

