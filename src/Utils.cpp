#include "../headers/exceptions/InvalidArgumentException.h"
#include "../headers/FlightAttendant.h"
#include "../headers/FlightEngineer.h"
#include "../headers/Utils.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>

std::string Utils::generateID() {
    std::string id = "";
    for (int i = 0;i < Utils::ID_LENGTH;++i)
        id += Utils::digits.at(rand() % Utils::digits.size());

    return  id;
}

std::shared_ptr<AircraftCrewMember> Utils::generateCrewMember(bool pilot, const std::string& license) {
    auto id = Utils::generateID();
    auto name = Utils::lastNames.at(rand() % Utils::lastNames.size());
    unsigned int salary = (pilot ? 100'000 : 60'000) + rand() % (pilot ? 40'000 : 20'000);

    if (pilot)
        return std::make_shared<Pilot>(id, name, salary, license);

    return std::make_shared<FlightAttendant>(id, name, salary);
}


std::shared_ptr<Passenger> Utils::generatePassenger(bool infant, const std::shared_ptr<Passenger>& caretaker) {
    auto firstName = Utils::firstNames.at(rand() % Utils::firstNames.size());
    auto lastName = Utils::lastNames.at(rand() % Utils::lastNames.size());
    auto street = Utils::streets.at((rand() % Utils::streets.size()));
    auto city = Utils::cities.at(rand() % Utils::cities.size());
    auto country = Utils::countries.at(rand() % Utils::countries.size());
    auto id = Utils::generateID();
    // added an age offset so that a normal passenger(not infant) should be at least 2yo
    unsigned int age = (infant ? 0 : 2) + rand() % (infant ? 2 : 90);

    return infant ? std::make_shared<InfantPassenger>(firstName, lastName, id, age, Address(street, city, country), caretaker)
            : std::make_shared<Passenger>(firstName, lastName, id, age, Address(street, city, country));
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

    // add passengers and crew to flights
    for (auto& flight : airline.getFlights()) {
        airline.addFlightCrew(flight, Utils::generateCrewMember(true, "LICENSE 45678976"));
        for (int i = 0; i < Utils::FLIGHT_ATTENDANTS;++i)
            airline.addFlightCrew(flight, Utils::generateCrewMember());

        // todo replace this with a factory!
        airline.addFlightCrew(flight, std::make_shared<FlightEngineer>(Utils::generateID(),
                                                     Utils::lastNames.at(rand() % Utils::lastNames.size()),
                                                     80'000,
                                                     5));

        int infantsCount = rand() % (Utils::MAX_INFANTS + 1);
        std::vector<std::shared_ptr<Passenger>> passengers;

        for (int i = 0; i < flight.getAircraft().getCapacity() - infantsCount; ++i) {
            auto passenger = Utils::generatePassenger();
            airline.addFlightPassenger(flight, passenger);
            passengers.push_back(passenger);
        }

        for (int i = 0;i < infantsCount; ++i) {
            try {
                auto caretaker = passengers[rand() % passengers.size()];
                auto infant = Utils::generatePassenger(true, caretaker);
                airline.addFlightPassenger(flight, infant);
            } catch (const InvalidArgumentException& exception) {
                std::cerr << exception.what() << "\n";
            }
        }
    }

    return airline;
}
