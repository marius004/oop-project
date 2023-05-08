#ifndef FLIGHTSTATUS_H
#define FLIGHTSTATUS_H

enum FlightStatus {
    SCHEDULED,
    FLYING,
    CANCELLED [[maybe_unused]],
    LANDING,
    LANDED,
};

#endif //FLIGHTSTATUS_H
