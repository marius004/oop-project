#include <utility>

#include "../headers/AircraftCrewMember.h"

AircraftCrewMember::AircraftCrewMember(std::string id, std::string name, unsigned int salary)
    : Employee(std::move(id), std::move(name), salary) {}
