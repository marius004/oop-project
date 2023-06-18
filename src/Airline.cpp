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

void Airline::addFlight(const Flight& flight) {
    flights.push_back(flight);
}

void Airline::addFlightPassenger(const Flight &flight, std::shared_ptr<Passenger> passenger) {
    auto flightIterator = std::find(flights.begin(), flights.end(), flight);
    if (flightIterator != flights.end())
        flightIterator->addPassenger(passenger);
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

void Airline::handleFlightsLandingNow(const std::vector<Flight>& flights) {
    for (const auto& flight : flights) {
        std::cout << "Flight " << flight.getNumber() << " has just landed\n";
        updateFlightStatus(flight, FlightStatus::LANDED);
    }
}

void Airline::handleFlightsPreparingForLanding(const std::vector<Flight>& flights) {
    for (const auto& flight : flights)
        prepareForLanding(flight);
}

void Airline::handleFlightsTakingOff(time_t time, const std::vector<Flight>& flights) {
    for (const auto& flight : flights) {
        if (!flight.getAircraft().canFly()) {
            std::cout << "Performing maintenance for aircraft " << flight.getAircraft() << "\n";
            maintainAircraft(flight.getAircraft(), time);
        }

        try {
            // cloning just to get rid of the warning
            auto pilot = getFlightPilot(flight)->clone();
            std::cout << "The pilot for flight " << flight.getNumber() << " is " << pilot->getName() << "\n";
        } catch (const NoFlightPilotException& exception) {
            std::cerr << exception.what();
            cancelFlight(flight);
            continue;
        } catch (const InvalidPilotLicenseException& exception) {
            std::cerr << exception.what();
            cancelFlight(flight);
            continue;
        }

        introduceCrew(flight);
        updateFlightStatus(flight, FlightStatus::FLYING);
    }
}

void Airline::simulate(time_t time) {
    handleFlightsLandingNow(searchByCriteria(this->flights, [&](const Flight& flight) {
            return flight.getEstimatedLanding() == time;
    }));

    handleFlightsTakingOff(time, searchByCriteria(this->flights, [&](const Flight& flight) {
        return flight.getStart() == time;
    }));

    handleFlightsPreparingForLanding(searchByCriteria(this->flights, [&](const Flight& flight) {
        return flight.getEstimatedLanding() - 1 == time;
    }));
}

void Airline::cancelFlight(const Flight &flight) {
    std::cout << "Cancelling flight " << flight.getNumber() << "\n";
    updateFlightStatus(flight, FlightStatus::CANCELLED);
}

std::shared_ptr<Pilot> Airline::getFlightPilot(const Flight &flight) {
    auto flightIterator = std::find(flights.begin(), flights.end(), flight);
    for (const auto& member : flightIterator->getCrew())
        if (auto pilot = std::dynamic_pointer_cast<Pilot>(member); pilot != nullptr)
            return pilot;
    throw NoFlightPilotException(flightIterator->getNumber());
}

void Airline::introduceCrew(const Flight& flight) {
    for (const auto& member : flight.getCrew())
        member->introduce(flight.getNumber(), flight.getDestinationCity());
}

void Airline::prepareForLanding(const Flight &flight) {
    for (const auto& crew : flight.getCrew())
        crew->prepareForLanding(flight.getDestinationCity(), flight.getPassengers());
}

std::shared_ptr<Airline> Airline::clone() const {
    return std::make_shared<Airline>(*this);
}

template<typename T, typename F>
std::vector<T> Airline::searchByCriteria(const std::vector<T> &items, F criteria) {
    std::vector<T> result;
    for (const T& item : items)
        if (criteria(item))
            result.push_back(item);

    return result;
}
