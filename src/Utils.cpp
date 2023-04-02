#include "../headers/Utils.h"
#include <cstdlib>
#include <string>
#include <vector>

std::string Utils::generateID() {
    std::string id = "";
    for (int i = 0;i < Utils::ID_LENGTH;++i)
        id += Utils::digits.at(rand() % Utils::digits.size());

    return  id;
}

Passenger Utils::generatePassenger() {
    auto firstName = Utils::firstNames.at(rand() % Utils::firstNames.size());
    auto lastName = Utils::lastNames.at(rand() % Utils::lastNames.size());
    auto street = Utils::streets.at((rand() % Utils::streets.size()));
    auto city = Utils::cities.at(rand() % Utils::cities.size());
    auto country = Utils::countries.at(rand() % Utils::countries.size());
    auto id = Utils::generateID();

    return {firstName, lastName, id, Address(street, city, country)};
}

Aircraft Utils::generateAircraft() {
    auto manufacturer = Utils::manufacturers.at(rand() % Utils::manufacturers.size());
    auto model = Utils::models.at(rand() % Utils::models.size());
    auto year = Utils::AIRCRAFT_MIN_MANUFACTURING_YEAR + rand() % 33;
    auto capacity = Utils::AIRCRAFT_MIN_CAPACITY + rand() % 151;
    auto revision = -1 * (rand() % Utils::AIRCRAFT_MIN_REVISION_YEAR);

    return {manufacturer, model, year, capacity, revision};
}

std::string Utils::generateFlightNumber() {
    std::string number;
    for (int i = 0;i < Utils::FLIGHT_NUMBER_LENGTH; ++i)
        number += Utils::digits.at(rand() % Utils::digits.size());

    return number;
}

Address Utils::generateAddress() {
    return {Utils::streets.at(rand() % Utils::streets.size()),
                   Utils::cities.at(rand() % Utils::cities.size()),
                   Utils::countries.at(rand() % Utils::countries.size())};
}

Airline Utils::generateAirline(const std::string &name, int aircraftCount, int flightCount) {
    std::vector<Aircraft> aircraft;
    for (int i = 0;i < aircraftCount;++i)
        aircraft.push_back(Utils::generateAircraft());

    Airline airline(name);
    airline.addAircraft(aircraft);

    int count = 0;
    int aircraftIndex = 0;
    time_t time = 0;

    while (count < flightCount) {
        int toAdd = rand() % aircraftCount;

        for (int i = 0;i < toAdd && count < flightCount;++i) {
            airline.addFlight(Utils::generateFlightNumber(), time, rand() % Utils::MAX_FLIGHT_DURATION,
                              Utils::generateAddress(), Utils::generateAddress(), aircraft[aircraftIndex]);

            aircraftIndex = (aircraftIndex + 1) % aircraftCount;
            count++;
        }

        time++;
    }

    // add passengers to flights
    for (auto& flight : airline.getFlights())
        for (int i = 0;i < flight.getAircraft().getCapacity(); ++i)
            airline.addFlightPassenger(flight, Utils::generatePassenger());

    return airline;
}
