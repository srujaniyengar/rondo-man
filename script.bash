#!/bin/bash

TARGET_DIR="$HOME/bin"
INSTALL_SYSTEM_WIDE=false

if [ "$1" == "--system" ]; then
    INSTALL_SYSTEM_WIDE=true
    TARGET_DIR="/usr/local/bin"
fi

if [ -d "$TARGET_DIR" ]; then
    echo "Directory $TARGET_DIR already exists. Adding the build..."
else
    echo "Directory $TARGET_DIR does not exist. Creating it..."
    mkdir -p "$TARGET_DIR"
fi

BINARY_PATH="./rondo-man"
SRC_DIR="src"
UTILS_DIR="utils"

echo "Compiling source files..."
g++ "$SRC_DIR/main.cpp" "$UTILS_DIR/cat.cpp" -o "$BINARY_PATH"

if [ -f "$BINARY_PATH" ]; then
    cp "$BINARY_PATH" "$TARGET_DIR/"
    echo "Build added to $TARGET_DIR."
else
    echo "Error: Binary $BINARY_PATH does not exist after compilation."
    exit 1
fi

chmod +x "$TARGET_DIR/rondo-man"
echo "Binary is now executable."

if [ "$INSTALL_SYSTEM_WIDE" = true ]; then
    echo "The program was installed system-wide to $TARGET_DIR. You may need to use sudo."
fi
