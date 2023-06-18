#ifndef OOP_AIRLINEBUILDER_H
#define OOP_AIRLINEBUILDER_H

#include "../headers/Airline.h"
#include <string>

class AirlineBuilder {
private:
    std::shared_ptr<Airline> instance;
public:
    explicit AirlineBuilder(std::string name);

    std::shared_ptr<Airline> build();

    AirlineBuilder withAircraft(const std::vector<Aircraft> &aircraft);

    AirlineBuilder withFlights(const std::vector<Flight> &flights);

    AirlineBuilder withFlightCrew(const Flight &flight, const std::vector<std::shared_ptr<AircraftCrewMember>> &crew);

    AirlineBuilder withFlightPassengers(const Flight &flight, const std::vector<std::shared_ptr<Passenger>> &passengers);
};

#endif //OOP_AIRLINEBUILDER_H
