#include "../utils/cat.h"
#include <cstdlib>
#include <iostream>

void show_help() {
    std::cout << "Usages: rondo-man [cmd]\n";
    std::cout << "Commands:\n";
    std::cout << "  time <min> <end_message>  Sets a timer for \"min\" and greets with and end message \n";
    std::cout << "  cAt!                      Generates random ASCII cat image\n";
    std::cout << "  --help                    Show this help message\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments.\n";
        show_help();
        return 1;
    }

    std::string cmd = argv[1];

    if (cmd == "cAt!") {
        Cat cat;
        cat.dispCatRand();
    }
    else if (cmd == "--help") {
        show_help();
    }
    else {
        std::cerr << "Error: Unknown command '" << cmd << "'.\n";
        show_help();
        return 1;
    }

    return 0;
}
