
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -static-libstdc++ -static-libgcc  # Ensure compatibility
TARGET = rondo-man
SRC_DIR = src
UTILS_DIR = utils
SRC = $(SRC_DIR)/main.cpp $(UTILS_DIR)/cat.cpp $(UTILS_DIR)/size.cpp $(UTILS_DIR)/timer.cpp
OBJ = $(SRC:.cpp=.o)
INSTALL_DIR = /usr/local/bin

# Detect OS
OS := $(shell uname -s)

# Handle different OS environments
ifeq ($(OS),Linux)
    ifeq ($(shell grep -i ubuntu /etc/os-release 2>/dev/null),)
        CXXFLAGS += -DARCH_LINUX
    else
        CXXFLAGS += -DUBUNTU
    endif
endif

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL_DIR)..."
	@sudo cp $(TARGET) $(INSTALL_DIR)
	@echo "Installation complete!"

uninstall:
	@echo "Removing $(TARGET) from $(INSTALL_DIR)..."
	@sudo rm -f $(INSTALL_DIR)/$(TARGET)
	@echo "Uninstallation complete!"

