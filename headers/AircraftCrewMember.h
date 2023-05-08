#ifndef OOP_AIRCRAFTCREWMEMBER_H
#define OOP_AIRCRAFTCREWMEMBER_H

#include "../headers/Passenger.h"
#include "../headers/Employee.h"
#include "../headers/Aircraft.h"

#include <unordered_set>
#include <string>
#include <memory>


class AircraftCrewMember : public Employee {
public:
    AircraftCrewMember(std::string id, std::string name, unsigned int salary);

    virtual std::string introduce(std::string flightNumber, std::string city) const = 0;
    virtual void prepareForLanding(std::string destination, std::unordered_set<std::shared_ptr<Passenger>> passengers) const = 0;
    virtual bool canFly() const = 0;
    virtual std::shared_ptr<AircraftCrewMember> clone() const = 0;
};

#endif //OOP_AIRCRAFTCREWMEMBER_H
