
CXX = g++
CXXFLAGS = -std=c++14 -Wall
TARGET = rondo-man
SRC_DIR = src
UTILS_DIR = utils
SRC = $(SRC_DIR)/main.cpp $(UTILS_DIR)/cat.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin

uninstall:
	@echo "Removing $(TARGET) from /usr/local/bin..."
	@sudo rm -f /usr/local/bin/$(TARGET)
