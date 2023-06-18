#ifndef OOP_PASSENGERFACTORY_H
#define OOP_PASSENGERFACTORY_H

#include "AircraftCrewMember.h"
#include "Passenger.h"
#include <memory>
#include <string>
#include <vector>

class PassengerFactory {
public:
    virtual std::shared_ptr<Passenger> createPassenger(bool infant = false, const std::shared_ptr<Passenger>& caretaker = {}) const = 0;
    virtual std::shared_ptr<AircraftCrewMember> createCrewMember(bool pilot = false, const std::string& license = "") const = 0;
    virtual ~PassengerFactory() = default;
};

#endif //OOP_PASSENGERFACTORY_H
