
#include "../utils/cat.h"
#include "../utils/timer.h"
#include "../utils/size.h"
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <string_view>

namespace fs = std::filesystem;

void show_help() {
    std::cout << "Usages: rondo-man [cmd]\n";
    std::cout << "Commands:\n";
    std::cout << "  size <path>               Shows the space in the current path\n";
    std::cout << "  size                      Shows the space in home directory \n";
    std::cout << "  cAt!                      Generates random ASCII cat image\n";
    std::cout << "  timer <minutes>           Sets a countdown timer for specified minutes\n";
    std::cout << "  timer <minutes> <seconds> Sets a countdown timer for minutes and seconds\n";
    std::cout << "  --help                    Show this help message\n";
}

enum Command {
    HELP,
    CAT,
    SIZE,
    TIMER,
    UNKNOWN
};

Command getCommand(std::string_view cmd) {
    if (cmd == "--help") return HELP;
    if (cmd == "cAt!") return CAT;
    if (cmd == "size") return SIZE;
    if (cmd == "timer") return TIMER;
    return UNKNOWN;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "Error: Invalid number of arguments.\n";
        show_help();
        return 1;
    }

    switch (getCommand(argv[1])) {
        case CAT: {
            Cat cat;
            cat.dispCatRand();
            break;
        }
        
        case SIZE: {
            Size sizeCalc;
            if (argc == 2) {
                const char* homeDir = getenv("HOME");
                if (homeDir) {
                    std::cout << "Size of home directory: " 
                             << sizeCalc.getSize(fs::path(homeDir)) << std::endl;
                }
            } else if (argc == 3) {
                std::cout << "Size of " << argv[2] << ": " 
                         << sizeCalc.getSize(fs::path(argv[2])) << std::endl;
            }
            break;
        }

        case TIMER: {
            if (argc == 3) {
                Timer timer(std::stoi(argv[2]));
                timer.setTimer();
            } else if (argc == 4) {
                Timer timer(std::stoi(argv[2]), std::stoi(argv[3]));
                timer.setTimer();
            } else {
                std::cerr << "Error: Timer requires minutes or minutes and seconds\n";
                show_help();
                return 1;
            }
            break;
        }
        
        case HELP: {
            show_help();
            break;
        }
        
        case UNKNOWN:
        default: {
            std::cerr << "Error: Unknown command '" << argv[1] << "'.\n";
            show_help();
            return 1;
        }
    }

    return 0;
}

