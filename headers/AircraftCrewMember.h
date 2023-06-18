#ifndef OOP_AIRCRAFTCREWMEMBER_H
#define OOP_AIRCRAFTCREWMEMBER_H

#include "../headers/Passenger.h"
#include "../headers/Employee.h"
#include "../headers/Aircraft.h"

#include <vector>
#include <string>
#include <memory>

class AircraftCrewMember : public Employee {
public:
    AircraftCrewMember(std::string id, std::string name, unsigned int salary);

    [[nodiscard]] virtual std::string introduce(const std::string& flightNumber, const std::string& city) const = 0;
    virtual void prepareForLanding(const std::string& destination, std::vector<std::shared_ptr<Passenger>> passengers) const = 0;
    [[nodiscard]] virtual bool canFly() const = 0;
    virtual std::shared_ptr<AircraftCrewMember> clone() const = 0;
    virtual ~AircraftCrewMember() = default;
};

#endif //OOP_AIRCRAFTCREWMEMBER_H
