#include "headers/RandomPassengerFactory.h"
#include "headers/RandomAddressFactory.h"
#include "headers/AirlineBuilder.h"
#include "headers/Airline.h"
#include "headers/Utils.h"
#include <cstdlib>
#include <string>
#include <ctime>

std::shared_ptr<Airline> buildAirline(const std::string& name, int aircraftCount, int flightCount) {
    auto addressFactory   = std::make_shared<RandomAddressFactory>();
    auto passengerFactory = std::make_shared<RandomPassengerFactory>(addressFactory);

    auto aircraft = Utils::buildAircraft(aircraftCount);
    auto flights = Utils::buildFlights(aircraftCount, flightCount, aircraft, addressFactory);

    auto builder = AirlineBuilder(name)
        .withAircraft(aircraft)
        .withFlights(flights);

    for (const auto& flight : flights)
        builder = builder
                    .withFlightCrew(flight, Utils::buildCrew(passengerFactory))
                    .withFlightPassengers(flight, Utils::buildPassengers(flight, passengerFactory));

    return builder.build();
}

int main() {
    srand (time(nullptr));

    bool isRunning = true;
    std::time_t time = 0;

    auto airline = buildAirline("Otopeni", 10, 50);
    while (isRunning) {
        airline->simulate(time);

        time++;
        if (time >= 30)
            isRunning = false;
    }

    return 0;
}