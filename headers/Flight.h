#ifndef FLIGHT_H
#define FLIGHT_H

#include <ostream>
#include <string>
#include <vector>
#include <ctime>

#include "FlightStatus.h"
#include "Passenger.h"
#include "Aircraft.h"
#include "Address.h"

class Flight {
private:
    std::string number;
    std::time_t start;
    std::time_t duration;

    Address source;
    Address destination;
    Aircraft aircraft;
    FlightStatus status;

    std::vector<Passenger> passengers;
public:

    Flight(std::string number, time_t start, time_t duration, Address source, Address destination, Aircraft aircraft);

    Flight(const Flight& flight);

    void setStatus(FlightStatus status);

    [[nodiscard]]
    FlightStatus getStatus() const;

    [[nodiscard]]
    time_t getStart() const;

    [[nodiscard]]
    const Aircraft &getAircraft() const;

    [[nodiscard]]
    const std::string &getNumber() const;

    [[nodiscard]]
    time_t getDuration() const;

    [[nodiscard]]
    bool addPassenger(const Passenger& passenger);

    friend std::ostream &operator<<(std::ostream &os, const Flight &flight);

    Flight& operator=(const Flight& other);

    ~Flight();

    bool operator==(const Flight &rhs) const;

    bool operator!=(const Flight &rhs) const;
};

#endif //FLIGHT_H
