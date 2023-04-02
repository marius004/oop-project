#include <iostream>
#include <cstdlib>
#include <ctime>

#include "headers/Airline.h"
#include "headers/Utils.h"

void run(Airline& airline, std::time_t time) {
    for (const auto& flight :  airline.getFlights(time)) {
        std::cout << flight << "\n";
        if (flight.getStart() + flight.getDuration() == time) {
            std::cout << "Flight " << flight.getNumber() << " has just landed\n";
            airline.updateFlightStatus(flight, FlightStatus::LANDED);
            continue;
        } else if (flight.getStart() == time) {
            if (!flight.getAircraft().canFly()) {
                std::cout << "Performing maintenance for aircraft " << flight.getAircraft() << "\n";
                airline.maintainAircraft(flight.getAircraft(), time);
            }

            airline.updateFlightStatus(flight, FlightStatus::FLYING);
            continue;
        }

        std::cout << "Flight " << flight.getNumber() << " is still flying\n";
    }
}

int main() {
    srand (time(nullptr));

    bool isRunning = true;
    std::time_t time = 0;

    auto airline = Utils::generateAirline("Otopeni", 10, 100);

    while (isRunning) {
        run(airline, time);

        time++;
        if (time >= 100)
            isRunning = false;
    }

    return 0;
}