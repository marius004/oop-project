#include "../headers/exceptions/InvalidArgumentException.h"
#include "../headers/FlightAttendant.h"
#include "../headers/Utils.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>

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
        number += char('0' + rand() % 10);

    return number;
}

std::vector<Flight> Utils::buildFlights(int aircraftCount, int flightCount, std::vector<Aircraft> aircraft, std::shared_ptr<AddressFactory> addressFactory) {
    int count = 0;
    int aircraftIndex = 0;
    time_t time = 0;

    std::vector<Flight> flights;
    while (count < flightCount) {
        int toAdd = rand() % aircraftCount;
        for (int i = 0;i < toAdd && count < flightCount;++i) {
            flights.emplace_back(Utils::generateFlightNumber(), time, rand() % Utils::MAX_FLIGHT_DURATION, addressFactory->create(), addressFactory->create(),  aircraft[aircraftIndex]);
            aircraftIndex = (aircraftIndex + 1) % aircraftCount;
            count++;
        }

        time++;
    }

    return flights;
}

std::vector<Aircraft> Utils::buildAircraft(int aircraftCount) {
    std::vector<Aircraft> aircraft;
    for (int i = 0;i < aircraftCount;++i)
        aircraft.push_back(Utils::generateAircraft());

    return aircraft;
}

std::vector<std::shared_ptr<AircraftCrewMember>> Utils::buildCrew(const std::shared_ptr<PassengerFactory>& passengerFactory) {
    std::vector<std::shared_ptr<AircraftCrewMember>> crew;

    crew.push_back(passengerFactory->createCrewMember(true, "LICENSE 45678976"));
    for (int i = 0; i < Utils::FLIGHT_ATTENDANTS;++i)
        crew.push_back(passengerFactory->createCrewMember());

    return crew;
}

std::vector<std::shared_ptr<Passenger>> Utils::buildPassengers(const Flight& flight, const std::shared_ptr<PassengerFactory>& passengerFactory) {
    std::vector<std::shared_ptr<Passenger>> passengers;

    int infantsCount = rand() % (Utils::MAX_INFANTS + 1);
    for (int i = 0; i < flight.getAircraft().getCapacity() - infantsCount; ++i) {
        auto passenger = passengerFactory->createPassenger();
        passengers.push_back(passenger);
    }

    int size = (int) passengers.size();
    for (int i = 0;i < infantsCount; ++i) {
        try {
            auto caretaker = passengers[rand() % size];
            auto infant = passengerFactory->createPassenger(true, caretaker);
            passengers.push_back(infant);
        } catch (const InvalidArgumentException& exception) {
            std::cerr << exception.what() << "\n";
        }
    }

    return passengers;
}
