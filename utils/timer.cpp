
#include "timer.h"

Timer::Timer() {
    min = 0;
    sec = 0;
}

Timer::Timer(int seconds) {
    min = seconds / 60;
    sec = seconds % 60;
}

Timer::Timer(int minutes, int seconds) {
    min = minutes;
    sec = seconds;
}

void Timer::setTimer() {
    std::cout << "\033[2J\033[1;1H"; // Clear screen
    std::cout << "\033[1;32m"; // Green text

    while (min >= 0) {
        while (sec >= 0) {
            std::cout << "\033[1;1H"; // Move cursor to top
            std::cout << "+--------------------+\n";
            std::cout << "|    TIME REMAINING  |\n";
            std::cout << "|        " << min << ":"
                     << (sec < 10 ? "0" : "") << sec
                     << "        |\n";
            std::cout << "+--------------------+\n";
            
            // Progress bar
            std::cout << "[";
            for (int i = 0; i < 20; i++) {
                if (i < sec % 20) std::cout << "#";
                else std::cout << " ";
            }
            std::cout << "]\n";
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            sec--;
        }
        if (min > 0) {
            min--;
            sec = 59;
        } else {
            break;
        }
    }
    
    std::cout << "\033[1;31m"; // Red text
    std::cout << "\n*** TIMER COMPLETED ***\n";
    std::cout << "\033[0m"; // Reset color
}
