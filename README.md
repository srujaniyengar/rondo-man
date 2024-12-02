
# rondo-man

rondo-Man is a Linux utility designed to simplify common tasks with an array of helpful features that can be accessed via the command line. From cleaning up temporary files to generating random ASCII art, rondo-Man makes your workflow easier and more fun!

## Features

- Delete Temporary or Unused Files: Remove files that haven’t been accessed in a specified time period.
- Create Temporary File for Coding: Automatically create a temporary file and open it in Neovim for quick coding.
- Random ASCII Art Generator: Display a random ASCII logo or pattern every time you run the tool.
- Calculate Directory Size: Quickly calculate and display the size of a directory, including its subdirectories.
- Custom Timer/Reminder Tool: Set up custom timers and receive notifications when they expire.
- Display Current Running Tasks: View the tasks currently running on your system.

## Prerequisites

Before you begin, make sure you have the following installed:

- g++: The GNU C++ compiler for building the utility.
- neovim: A modern text editor for coding.
- make: For automating the build process.
- CMake: To configure and generate build files.

### For Arch Linux

You can install the dependencies using pacman:

    sudo pacman -S g++ neovim make cmake

### For Ubuntu/Debian-based Systems

To install the dependencies on Linux (Ubuntu/Debian):

    sudo apt-get update
    sudo apt-get install g++ neovim make cmake

## Installation

You can install rondo-Man using CMake by following these steps:

### 1. Build from Source Using CMake

Follow these steps to compile rondo-Man from source:

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/rondo-man.git
    cd rondo-man
    ```

2. Create a build directory:

    ```bash
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:

    ```bash
    cmake ..
    ```

4. Compile the source code:

    ```bash
    make
    ```

5. (Optional) Install the binary to a directory in your `$PATH`:

    ```bash
    sudo make install
    ```

### 2. Usage

Once installed, you can run rondo-Man from the command line with various commands:

- **Generate a random ASCII cat image**:

    ```bash
    rondo-man cAt!
    ```

- **Display help information**:

    ```bash
    rondo-man --help
    ```

- **Delete unused files (use with caution)**:

    ```bash
    rondo-man delete --older-than 30
    ```

    This deletes files not accessed in the last 30 days.

- **Create a temporary file for coding and open it in Neovim**:

    ```bash
    rondo-man create-temp-file
    ```

- **Calculate and display the size of a directory**:

    ```bash
    rondo-man size /path/to/directory
    ```

- **Set a custom timer/reminder (in minutes)**:

    ```bash
    rondo-man timer 10
    ```

    This command sets a timer for 10 minutes.

- **Display current running tasks**:

    ```bash
    rondo-man tasks
    ```

    Shows currently running tasks on your system.

## Contributing

Contributions to rondo-Man are welcome! Feel free to open issues or submit pull requests if you have suggestions or improvements.
