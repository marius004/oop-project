#ifndef OOP_OBJECTFACTORY_H
#define OOP_OBJECTFACTORY_H

#include "../../headers/AircraftCrewMember.h"
#include "../../headers/Passenger.h"
#include "../../headers/Airline.h"
#include "../../headers/Address.h"

#include <memory>

// todo: decide what arguments should be passed to the factory
class ObjectFactory {
public:
    [[nodiscard]] virtual std::shared_ptr<Passenger> createPassenger() const = 0;
    [[nodiscard]] virtual std::shared_ptr<AircraftCrewMember> createCrewMember() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Aircraft> createAircraft() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Address> createAddress() const = 0;
    [[nodiscard]] virtual std::shared_ptr<Airline> createAirline() const = 0;

    virtual ~ObjectFactory() = default;
};

#endif //OOP_OBJECTFACTORY_H
