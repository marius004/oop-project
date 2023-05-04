#include "../headers/exceptions/InvalidArgumentException.h"
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
    unsigned  int age = rand() % 90;

    return {firstName, lastName, id, age, Address(street, city, country)};
}

// todo: maybe a factory for this and get rid of bad practices(violating DRY)
InfantPassenger Utils::generateInfant(std::shared_ptr<Passenger> caretaker) {
    auto firstName = Utils::firstNames.at(rand() % Utils::firstNames.size());
    auto lastName = Utils::lastNames.at(rand() % Utils::lastNames.size());
    auto street = Utils::streets.at((rand() % Utils::streets.size()));
    auto city = Utils::cities.at(rand() % Utils::cities.size());
    auto country = Utils::countries.at(rand() % Utils::countries.size());
    auto id = Utils::generateID();

    // 5 is on purpose (to generate inconvenient data)
    // (age should be less than or equal to 2 to be considered 'infant')
    unsigned  int age = rand() % 5;

    return {firstName, lastName, id, age, Address(street, city, country), caretaker};
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
    for (auto& flight : airline.getFlights()) {
        int infantsCount = rand() % (Utils::MAX_INFANTS + 1);

        std::vector<Passenger> passengers;
        for (int i = 0; i < flight.getAircraft().getCapacity() - infantsCount; ++i) {
            auto passenger = Utils::generatePassenger();
            airline.addFlightPassenger(flight, passenger);
            passengers.push_back(passenger);
        }

        for (int i = 0;i < infantsCount; ++i) {
            try {
                auto caretaker = std::make_shared<Passenger>(passengers[rand() % passengers.size()]);
                auto infant = Utils::generateInfant(caretaker);
                airline.addFlightPassenger(flight, infant);
            } catch (const InvalidArgumentException& exception) {
                std::cerr << exception.what() << "\n";
            }
        }
    }

    return airline;
}
