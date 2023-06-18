#ifndef AIRLINE_H
#define AIRLINE_H

#include "AircraftCrewMember.h"
#include "Aircraft.h"
#include "Flight.h"

#include <ostream>
#include <string>
#include <vector>

class Airline : public Cloneable<Airline> {
private:
    std::string name;
    std::vector<Aircraft> fleet;
    std::vector<Flight> flights;

    void cancelFlight(const Flight &flight);

    std::shared_ptr<Pilot> getFlightPilot(const Flight &flight);

    static void introduceCrew(const Flight &flight);

    static void prepareForLanding(const Flight &flight);

public:
    explicit Airline(std::string name);

    void addAircraft(const Aircraft &aircraft);

    void simulate(time_t time);

    void addFlight(const Flight &flight);

    void addFlightPassenger(const Flight &flight, const std::shared_ptr<Passenger>& passenger);

    void addFlightCrew(const Flight &flight, const std::shared_ptr<AircraftCrewMember> &member);

    void updateFlightStatus(const Flight &flight, const FlightStatus &status);

    void maintainAircraft(const Aircraft &aircraft, time_t time);

    bool operator==(const Airline &rhs) const;

    bool operator!=(const Airline &rhs) const;

    template<typename T, typename F>
    std::vector<T> searchByCriteria(const std::vector<T> &items, F criteria);

    [[nodiscard]] std::shared_ptr<Airline> clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Airline &airline);

    virtual ~Airline() = default;

    void handleFlightsLandingNow(const std::vector<Flight> &landingFlights);

    static void handleFlightsPreparingForLanding(const std::vector<Flight> &flights);

    void handleFlightsTakingOff(time_t time, const std::vector<Flight> &flights);
};

#endif //AIRLINE_H