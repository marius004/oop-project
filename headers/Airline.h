#ifndef AIRLINE_H
#define AIRLINE_H

#include "Aircraft.h"
#include "Flight.h"

#include <string>
#include <vector>
#include <ostream>

class Airline {
private:
    std::string name;
    std::vector<Aircraft> fleet;
    std::vector<Flight> flights;

    bool containsAircraft(const Aircraft& aircraft);

    [[maybe_unused]]
    bool containsFlight(const Flight& flight);

public:
    explicit Airline(std::string name);

    [[nodiscard]]
    const std::vector<Flight> &getFlights() const;

    [[maybe_unused]] [[nodiscard]]
    const std::string &getName() const;

    [[maybe_unused]] [[nodiscard]]
    const std::vector<Aircraft> &getFleet() const;

    void addAircraft(const Aircraft& aircraft);

    void addAircraft(const std::vector<Aircraft>& aircraft);

    bool addFlight(const std::string& number,time_t start, time_t duration, const Address& source,
                   const Address& destination, const Aircraft& aircraft);

    bool addFlightPassenger(const Flight& flight, const Passenger& passenger);

    [[maybe_unused]]
    int addFlightPassengers(const Flight& flight, const std::vector<Passenger>& passengers);

    void updateFlightStatus(const Flight& flight, const FlightStatus& status);

    void maintainAircraft(const Aircraft& aircraft, time_t time);

    [[nodiscard]]
    std::vector<Flight> getFlights(time_t time) const;

    bool operator==(const Airline &rhs) const;

    bool operator!=(const Airline &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Airline &airline);
};

#endif //AIRLINE_H