#ifndef AIRLINE_H
#define AIRLINE_H

#include "AircraftCrewMember.h"
#include "Aircraft.h"
#include "Flight.h"

#include <ostream>
#include <string>
#include <vector>

class Airline {
private:
    std::string name;
    std::vector<Aircraft> fleet;
    std::vector<Flight> flights;

    void cancelFlight(const Flight& flight);
    std::shared_ptr<Pilot> getFlightPilot(const Flight& flight);

public:
    explicit Airline(std::string name);

    void addAircraft(const Aircraft& aircraft);

    void addAircraft(const std::vector<Aircraft>& aircraft);

    void simulate(time_t time);

    void addFlight(const std::string& number,time_t start, time_t duration, const Address& source,
                   const Address& destination, const Aircraft& aircraft);

    void addFlightPassenger(const Flight& flight, std::shared_ptr<Passenger> passenger);

    void addFlightCrew(const Flight& flight, const std::shared_ptr<AircraftCrewMember>& member);

    void updateFlightStatus(const Flight& flight, const FlightStatus& status);

    void maintainAircraft(const Aircraft& aircraft, time_t time);

    static void introduceCrew(const Flight& flight);

    static void prepareForLanding(const Flight& flight);

    [[nodiscard]] std::vector<Flight> getFlights(time_t time) const;

    [[nodiscard]] const std::vector<Flight>& getFlights() const;

    bool operator==(const Airline &rhs) const;

    bool operator!=(const Airline &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Airline &airline);
};

#endif //AIRLINE_H