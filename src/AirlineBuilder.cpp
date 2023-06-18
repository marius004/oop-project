#include "../headers/AirlineBuilder.h"

AirlineBuilder::AirlineBuilder(std::string name) {
    this->instance = std::make_shared<Airline>(name);
}

std::shared_ptr<Airline> AirlineBuilder::build() {
    return this->instance;
}

AirlineBuilder AirlineBuilder::withAircraft(const std::vector<Aircraft>& aircraft) {
    for (const auto& it : aircraft)
        this->instance->addAircraft(it);

    return *this;
}

AirlineBuilder AirlineBuilder::withFlights(const std::vector<Flight>& flights) {
    for (const auto& flight : flights)
        this->instance->addFlight(flight);

    return *this;
}

AirlineBuilder AirlineBuilder::withFlightCrew(const Flight &flight, const std::vector<std::shared_ptr<AircraftCrewMember>> &crew) {
    for (const auto& it : crew)
        this->instance->addFlightCrew(flight, it);

    return *this;
}

AirlineBuilder AirlineBuilder::withFlightPassengers(const Flight &flight, const std::vector<std::shared_ptr<Passenger>> &passengers) {
    for (const auto& passenger : passengers)
        this->instance->addFlightPassenger(flight, passenger);

    return *this;
}



