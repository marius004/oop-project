#ifndef OOP_AIRCRAFTCREWMEMBER_H
#define OOP_AIRCRAFTCREWMEMBER_H

#include "../headers/Cloneable.h"
#include"../headers/Passenger.h"
#include "../headers/Employee.h"
#include "../headers/Aircraft.h"

#include <unordered_set>
#include <vector>
#include <string>
#include <memory>

class AircraftCrewMember : public Employee, public Cloneable<AircraftCrewMember>  {
public:
    AircraftCrewMember(std::string id, std::string name, unsigned int salary);

    virtual std::string introduce(const std::string& flightNumber, const std::string& city) const = 0;
    virtual void prepareForLanding(const std::string& destination, std::unordered_set<std::shared_ptr<Passenger>> passengers) const = 0;
    virtual ~AircraftCrewMember() = default;
};

#endif //OOP_AIRCRAFTCREWMEMBER_H
