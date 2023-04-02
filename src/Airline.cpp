#include <utility>
#include <algorithm>

#include "../headers/Airline.h"

Airline::Airline(std::string name)
    : name(std::move(name)) {}

std::ostream &operator<<(std::ostream &os, const Airline &airline) {
    os << "Airline{" << "name: " << airline.name;

    os << " fleet: [";
    for (const auto& aircraft : airline.fleet)
        os << aircraft << ",";
    os << "]";

    os << "flights: [";
    for (const auto& flight : airline.flights)
        os << flight << ',';
    os << "]}";

    return os;
}

void Airline::addAircraft(const Aircraft &aircraft) {
    this->fleet.emplace_back(aircraft);
}

void Airline::addAircraft(const std::vector<Aircraft> &aircraft) {
    for (const auto& it : aircraft)
        this->addAircraft(it);
}

const std::vector<Flight> &Airline::getFlights() const {
    return flights;
}

bool Airline::containsAircraft(const Aircraft &aircraft) {
    return std::find(this->fleet.begin(), this->fleet.end(), aircraft) != this->fleet.end();
}

bool Airline::operator==(const Airline &rhs) const {
    return name == rhs.name &&
           fleet == rhs.fleet &&
           flights == rhs.flights;
}

bool Airline::operator!=(const Airline &rhs) const {
    return !(rhs == *this);
}

bool Airline::addFlight(const std::string &number, time_t start, time_t duration, const Address &source,
                        const Address &destination, const Aircraft &aircraft) {
    // if the given aircraft does not belong to the airline don't plan a flight
    if (!containsAircraft(aircraft))
        return false;

    auto flight = Flight(number, start, duration, source, destination, aircraft);
    this->flights.push_back(flight);

    return true;
}

bool Airline::addFlightPassenger(const Flight &flight, const Passenger &passenger) {
    auto flightPtr = std::find(flights.begin(), flights.end(), flight);
    if (flightPtr == flights.end())
        return false;

    return flightPtr->addPassenger(passenger);
}

std::vector<Flight> Airline::getFlights(time_t time) const {
    std::vector<Flight> ret;

    for (const auto& flight : this->flights)
        if (flight.getStart() == time ||
            (flight.getStart() + flight.getDuration()) == time ||
            flight.getStatus() == FlightStatus::FLYING)
            ret.push_back(flight);

    return ret;
}

void Airline::updateFlightStatus(const Flight &flight, const FlightStatus &status) {
    auto iter = std::find(this->flights.begin(), this->flights.end(), flight);
    if (iter == this->flights.end())
        return;

    iter->setStatus(status);
}

void Airline::maintainAircraft(const Aircraft &aircraft, time_t time) {
    auto iter = std::find(this->fleet.begin(), this->fleet.end(), aircraft);
    if (iter == this->fleet.end())
        return;

    iter->maintenance(time);
}
