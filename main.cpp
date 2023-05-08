#include "headers/Utils.h"
#include <cstdlib>
#include <ctime>


int main() {
    srand (time(nullptr));

    bool isRunning = true;
    std::time_t time = 0;

    auto airline = Utils::generateAirline("Otopeni", 10, 100);

    while (isRunning) {
        airline.simulate(time);

        time++;
        if (time >= 100)
            isRunning = false;
    }

    return 0;
}