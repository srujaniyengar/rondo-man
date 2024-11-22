rondo-Man

rondo-Man is a Linux utility designed to make your day-to-day tasks easier with some cool features! It can help you with cleaning up temporary files, generating random ASCII art, calculating the size of directories, and more—all from the command line.

Features:
- Deletes Temporary or Unused Files: Removes files that have not been used in a specified time period.
- Create Temporary File for Coding: Creates a temporary file for coding and opens it in Neovim.
- Random ASCII Art Generator: Displays a random ASCII logo or pattern on execution.
- Calculate Directory Size: Quickly calculates and displays the total size of a directory and its subdirectories.
- Custom Timer/Reminder Tool: Set up custom timers and receive notifications when they end.
- Displays Current Running Tasks: Displays the current running tasks on your system.

Prerequisites

To build rondo-Man from source, you'll need:
- g++: The GNU C++ compiler.
- neovim: A modern, powerful text editor for creating and editing code.
- make (optional): To automate the build process (for compiling and managing dependencies).

On Linux, you can install these dependencies using the following commands:

    sudo apt-get update
    sudo apt-get install g++ neovim make

Installing

You have a few ways to get started with rondo-Man:

1. Build it from source (manual installation)

To compile and install rondo-Man manually, follow these steps:

    1. Clone this repository:

       git clone https://github.com/yourusername/rondo-man.git
       cd rondo-man

    2. Compile the source code:

       g++ src/main.cpp utils/cat.cpp -o rondo-man

    3. Optionally, move the compiled binary to a directory in your $PATH, such as /usr/local/bin:

       sudo mv rondo-man /usr/local/bin/

    4. Make the binary executable (if not already done):

       sudo chmod +x /usr/local/bin/rondo-man

2. Using the provided script.bash

If you just want to install rondo-Man and don’t want to handle dependencies manually, use the script.bash included in the repository:

    1. Run the installation script:

       ./script.bash

       This script will compile the code and install rondo-Man into the appropriate directory ($HOME/bin or /usr/local/bin depending on the flag).

Usage

Once installed, you can run rondo-Man from the command line with one of the following commands:

- Generate a random ASCII art/logo or pattern:

    rondo-man

- Generate a random ASCII cat image:

    rondo-man cAt!

- Display help information:

    rondo-man --help

- Delete unused files (use with caution):

    rondo-man delete --older-than 30

    This command deletes files that have not been used in the last 30 days.

- Create a temporary file for coding and open it in Neovim:

    rondo-man create-temp-file

- Calculate and display the size of a directory:

    rondo-man size /path/to/directory

- Set a custom timer/reminder:

    rondo-man timer 10

    This command sets a timer for 10 minutes.

- Display current running tasks:

    rondo-man tasks

    This command shows the currently running tasks on your system.

Contributing

Feel free to open issues or pull requests if you have suggestions or improvements for rondo-Man. We welcome contributions!

License

This project is licensed under the MIT License - see the LICENSE file for details.
