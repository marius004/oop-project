#include <utility>
#include <algorithm>

#include "../headers/Airline.h"
#include "../headers/exceptions/NoFlightPilotException.h"
#include "../headers/exceptions/InvalidPilotLicenseException.h"

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

bool Airline::operator==(const Airline &rhs) const {
    return name == rhs.name &&
           fleet == rhs.fleet &&
           flights == rhs.flights;
}

bool Airline::operator!=(const Airline &rhs) const {
    return !(rhs == *this);
}

void Airline::addFlight(const std::string &number, time_t start, time_t duration, const Address &source,
                        const Address &destination, const Aircraft &aircraft) {
    auto flight = Flight(number, start, duration, source, destination, aircraft);
    flights.push_back(flight);
}

void Airline::addFlightPassenger(const Flight &flight, std::shared_ptr<Passenger> passenger) {
    auto flightIterator = std::find(flights.begin(), flights.end(), flight);
    flightIterator->addPassenger(passenger);
}

std::vector<Flight> Airline::getFlights(time_t time) const {
    std::vector<Flight> ret;

    for (const auto& flight : this->flights)
        if (flight.getStart() == time ||
            (flight.getStart() + flight.getDuration()) == time ||
            flight.getStatus() == FlightStatus::FLYING)
            ret.emplace_back(flight);

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

void Airline::addFlightCrew(const Flight &flight, const std::shared_ptr<AircraftCrewMember>& member) {
    auto flightIterator = std::find(flights.begin(), flights.end(), flight);
    flightIterator->addCrewMember(member);
}

void Airline::simulate(time_t time) {
    for (const auto& flight :  getFlights(time)) {
        std::cout << flight << "\n";

        if (flight.getEstimatedLanding() == time) {
            std::cout << "Flight " << flight.getNumber() << " has just landed\n";
            updateFlightStatus(flight, FlightStatus::LANDED);
            continue;
        } else if (flight.getStart() == time) {
            if (!flight.getAircraft().canFly()) {
                std::cout << "Performing maintenance for aircraft " << flight.getAircraft() << "\n";
                maintainAircraft(flight.getAircraft(), time);
            }

            try {
                auto pilot = getFlightPilot(flight)->clone();
                std::cout << "The pilot for flight " << flight.getNumber() << " is " << pilot->getName();

                if (!pilot->canFly())
                    throw InvalidPilotLicenseException(pilot->getName());

            } catch (const NoFlightPilotException& exception) {
                std::cerr << exception.what();
                cancelFlight(flight);
            } catch (const InvalidPilotLicenseException& exception) {
                std::cerr << exception.what();
                cancelFlight(flight);
            }

            for (const auto& crew : flight.getCrew())
                crew->introduce(flight.getNumber(), flight.getDestination().getCity());

            updateFlightStatus(flight, FlightStatus::FLYING);
        } else if (flight.getEstimatedLanding() - 1 == time) {
            // prepare for landing
            for (const auto& crew : flight.getCrew())
                crew->prepareForLanding(flight.getDestination().getCity(), flight.getPassengers());
        }

        std::cout << "Flight " << flight.getNumber() << " is still flying\n";
    }
}

void Airline::cancelFlight(const Flight &flight) {
    std::cout << "Cancelling flight " << flight.getNumber() << "\n";
    updateFlightStatus(flight, FlightStatus::CANCELLED);
}

std::shared_ptr<Pilot> Airline::getFlightPilot(const Flight &flight) {
    auto flightIterator = std::find(flights.begin(), flights.end(), flight);
    for (const auto& member : flightIterator->getCrew())
        if (member->canFly())
            return std::dynamic_pointer_cast<Pilot>(member);

    throw NoFlightPilotException(flightIterator->getNumber());
}
