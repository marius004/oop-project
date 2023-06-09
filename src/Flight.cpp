#include <algorithm>
#include <iostream>
#include <utility>
#include <memory>

#include "../headers/exceptions/NoFlightPilotException.h"
#include "../headers/Flight.h"

Flight::Flight(std::string number, time_t start, time_t duration, Address source, Address destination, Aircraft aircraft)
               : number(std::move(number)), start(start),
                 duration(duration), source(std::move(source)),
                 destination(std::move(destination)),
                 aircraft(std::move(aircraft)), status(FlightStatus::SCHEDULED) {}

const std::string &Flight::getNumber() const {
    return number;
}

std::ostream &operator<<(std::ostream &os, const Flight &flight) {
    os << "Flight{" << "number: " << flight.number << " duration: " << flight.duration << " source: " << flight.source
       << " destination: " << flight.destination << "}";
    return os;
}

void Flight::addPassenger(const std::shared_ptr<Passenger>& passenger) {
    this->passengers.insert(passenger);
}

const Aircraft &Flight::getAircraft() const {
    return aircraft;
}

bool Flight::operator==(const Flight &rhs) const {
    return number == rhs.number &&
           start == rhs.start &&
           duration == rhs.duration &&
           source == rhs.source &&
           destination == rhs.destination &&
           aircraft == rhs.aircraft &&
           passengers == rhs.passengers;
}

bool Flight::operator!=(const Flight &rhs) const {
    return !(rhs == *this);
}

void Flight::setStatus(FlightStatus newStatus) {
    Flight::status = newStatus;
}

time_t Flight::getStart() const {
    return start;
}

Flight::Flight(const Flight &flight)
    : number(flight.number),
      start(flight.start),
      duration(flight.duration),
      source(flight.source),
      destination(flight.destination),
      aircraft(flight.aircraft),
      status(flight.status)
    {
    this->deepCopyPointerFields(flight);
}

Flight &Flight::operator=(const Flight &other) {
    if (this != &other) {
        this->number = other.number;
        this->start = other.start;
        this->duration = other.duration;
        this->source = other.source;
        this->destination = other.destination;
        this->aircraft = other.aircraft;
        this->status = other.status;
        this->deepCopyPointerFields(other);
    }
    return *this;
}

Flight::~Flight() {
    std::cout << "~Flight()\n";
}

void Flight::addCrewMember(const std::shared_ptr<AircraftCrewMember>& crewMember) {
    this->crew.insert(crewMember);
}

const std::unordered_set<std::shared_ptr<Passenger>> &Flight::getPassengers() const {
    return passengers;
}

time_t Flight::getEstimatedLanding() const {
    return this->start + this->duration;
}

const std::unordered_set<std::shared_ptr<AircraftCrewMember>> &Flight::getCrew() const {
    return crew;
}

void Flight::deepCopyPointerFields(const Flight &flight) {
    this->crew.clear();
    for (const auto& member : flight.crew)
        this->crew.insert(member->clone());

    this->passengers.clear();
    for (const auto& passenger : flight.passengers)
        this->passengers.insert(std::shared_ptr<Passenger>(passenger));
}

Flight::Flight(const Flight &&flight) noexcept :
        number(flight.number),
        start(flight.start),
        duration(flight.duration),
        source(flight.source),
        destination(flight.destination),
        aircraft(flight.aircraft),
        status(flight.status),
        passengers(flight.passengers),
        crew(flight.crew)
    {}

const std::string &Flight::getDestinationCity() const {
    return this->destination.getCity();
}
