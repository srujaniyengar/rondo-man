
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = rondo-man
SRC_DIR = src
UTILS_DIR = utils
SRC = $(SRC_DIR)/main.cpp $(UTILS_DIR)/cat.cpp $(UTILS_DIR)/size.cpp
OBJ = $(SRC:.cpp=.o)
INSTALL_DIR = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

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

