#ifndef FLIGHT_H
#define FLIGHT_H

#include <unordered_set>
#include <ostream>
#include <string>
#include <memory>
#include <vector>
#include <ctime>

#include "AircraftCrewMember.h"
#include "FlightStatus.h"
#include "Passenger.h"
#include "Aircraft.h"
#include "Address.h"
#include "Pilot.h"

class Flight {
private:
    std::string number;
    std::time_t start;
    std::time_t duration;

    Address source;
    Address destination;
    Aircraft aircraft;
    FlightStatus status;

    std::vector<std::shared_ptr<Passenger>> passengers;
    std::vector<std::shared_ptr<AircraftCrewMember>> crew;

public:
    [[nodiscard]] const Address &getDestination() const;

    Flight(std::string number, time_t start, time_t duration, Address source, Address destination, Aircraft aircraft);

    Flight(const Flight& flight);

    void setStatus(FlightStatus status);

    [[nodiscard]] const std::vector<std::shared_ptr<AircraftCrewMember>> &getCrew() const;

    [[nodiscard]] const std::vector<std::shared_ptr<Passenger>> &getPassengers() const;

    [[nodiscard]] FlightStatus getStatus() const;

    [[nodiscard]] time_t getDuration() const;

    [[nodiscard]] time_t getStart() const;

    [[nodiscard]] time_t getEstimatedLanding() const;

    [[nodiscard]] const std::string &getNumber() const;

    [[nodiscard]] const Aircraft &getAircraft() const;

    void addPassenger(const std::shared_ptr<Passenger>& passenger);

    void addCrewMember(const std::shared_ptr<AircraftCrewMember>& crewMember);

    friend std::ostream &operator<<(std::ostream &os, const Flight &flight);

    Flight& operator=(const Flight& other);

    bool operator==(const Flight &rhs) const;
    bool operator!=(const Flight &rhs) const;

    ~Flight();
};

#endif //FLIGHT_H