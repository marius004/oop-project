#include <utility>
#include <iostream>

#include "../headers/Flight.h"

Flight::Flight(std::string number, time_t start, time_t duration, Address source, Address destination, Aircraft aircraft)
               : number(std::move(number)), start(start),
                 duration(duration), source(std::move(source)),
                 destination(std::move(destination)),
                 aircraft(std::move(aircraft)), status(FlightStatus::SCHEDULED) {}

const std::string &Flight::getNumber() const {
    return number;
}

time_t Flight::getDuration() const {
    return duration;
}

[[maybe_unused]] const Address &Flight::getSource() const {
    return source;
}

std::ostream &operator<<(std::ostream &os, const Flight &flight) {
    os << "Flight{" << "number: " << flight.number << " duration: " << flight.duration << " source: " << flight.source
       << " destination: " << flight.destination << "}";
    return os;
}

bool Flight::addPassenger(const Passenger &passenger) {
    auto iterator = std::find(this->passengers.begin(), this->passengers.end(), passenger);
    if (iterator != this->passengers.end())
        return false;

    this->passengers.emplace_back(passenger);
    return true;
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

FlightStatus Flight::getStatus() const {
    return status;
}

Flight::Flight(const Flight &flight)
    : number(flight.number),
      start(flight.start),
      duration(flight.duration),
      source(flight.source),
      destination(flight.destination),
      aircraft(flight.aircraft),
      status(flight.status),
      passengers(flight.passengers)
    {}

Flight &Flight::operator=(const Flight &other) {
    if (this != &other) {
        this->number = other.number;
        this->start = other.start;
        this->duration = other.duration;
        this->source = other.source;
        this->destination = other.destination;
        this->aircraft = other.aircraft;
        this->status = other.status;
        this->passengers = other.passengers;
    }

    return *this;
}

Flight::~Flight() {
    std::cout << "~Flight()\n";
}




