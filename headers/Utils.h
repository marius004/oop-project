#ifndef UTILS_H
#define UTILS_H

#include "Passenger.h"
#include "Aircraft.h"
#include "Airline.h"
#include "InfantPassenger.h"
#include "PassengerFactory.h"
#include "AddressFactory.h"

#include <vector>
#include <string>

class Utils {
private:
    inline static std::vector<std::string> manufacturers{"Boeing", "Airbus", "Embraer", "Cessna", "Bombardier"};
    inline static std::vector<std::string> models{"747", "A320", "E190", "172", "CRJ900"};

    inline static const int AIRCRAFT_MIN_MANUFACTURING_YEAR = 1990;
    inline static const int AIRCRAFT_MIN_CAPACITY = 100;
    inline static const int AIRCRAFT_MIN_REVISION_YEAR = 5;
    inline static const int MAX_INFANTS = 10;
    inline static const int FLIGHT_ATTENDANTS = 4;

public:
    inline static const int ID_LENGTH = 12;
    inline static const int FLIGHT_NUMBER_LENGTH = 5;
    inline static const int MAX_FLIGHT_DURATION = 12;
    inline static const time_t MAX_TIME_FLYING_WITHOUT_REVISION = 5;

    static std::string generateFlightNumber();

    static Aircraft generateAircraft();

    static std::vector<Flight> buildFlights(int aircraftCount, int flightCount, std::vector<Aircraft> aircraft, std::shared_ptr<AddressFactory> addressFactory);

    static std::vector<Aircraft> buildAircraft(int aircraftCount);

    static std::vector<std::shared_ptr<AircraftCrewMember>> buildCrew(const std::shared_ptr<PassengerFactory>& passengerFactory);

    static std::vector<std::shared_ptr<Passenger>>
    buildPassengers(const Flight &flight, const std::shared_ptr<PassengerFactory> &passengerFactory);
};

#endif //UTILS_H
