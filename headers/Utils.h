#ifndef UTILS_H
#define UTILS_H

#include "Passenger.h"
#include "Aircraft.h"
#include "Airline.h"

#include <vector>
#include <string>

class Utils {
private:

    inline static std::vector<std::string> firstNames = {"Popescu", "Birau", "Bratosin", "Horia", "Livia", "Alma", "Vicențiu", "Tania"};
    inline static std::vector<std::string> lastNames {"Alex", "Madalina", "Ciocirlan", "Calin", "Birsan", "Oana", "Nita"};
    inline static std::vector<std::string> streets {"Strada Costea Racovita", "Strada Danes", "Bulevardul Tudor Vladimirescu", "Strada Mihail Kogalniceanu", "Strada Ion Ratiu", "Strada Vasile Goldis" };
    inline static std::vector<std::string> cities {"Bucuresti", "Timisoara", "Cluj", "Craiova", "Constanta", "Arad"};
    inline static std::vector<std::string> countries {"Romania"};
    inline static std::vector<std::string> digits {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    inline static std::vector<std::string> manufacturers{"Boeing", "Airbus", "Embraer", "Cessna", "Bombardier"};
    inline static std::vector<std::string> models{"747", "A320", "E190", "172", "CRJ900"};

    inline static const int AIRCRAFT_MIN_MANUFACTURING_YEAR = 1990;
    inline static const int AIRCRAFT_MIN_CAPACITY = 100;
    inline static const int AIRCRAFT_MIN_REVISION_YEAR = 5;

    static std::string generateID();

public:
    inline static const int ID_LENGTH = 13;
    inline static const int FLIGHT_NUMBER_LENGTH = 5;
    inline static const int MAX_FLIGHT_DURATION = 12;
    inline static const time_t MAX_TIME_FLYING_WITHOUT_REVISION = 5;

    static Passenger generatePassenger();
    static Aircraft generateAircraft();
    static Address generateAddress();
    static std::string generateFlightNumber();
    static Airline generateAirline(const std::string& name, int aircraftCount, int flightCount);
};

#endif //UTILS_H
