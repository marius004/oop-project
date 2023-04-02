#include <utility>
#include "../headers/Passenger.h"

Passenger::Passenger(std::string firstName, std::string lastName, std::string id, Address address)
    : firstName(std::move(firstName)), lastName(std::move(lastName)), id(std::move(id)), address(std::move(address)) {}

std::ostream &operator<<(std::ostream &os, const Passenger &passenger) {
    os << "Passenger{" << "firstName: " << passenger.firstName << " lastName: " << passenger.lastName << " id: "
       << passenger.id << " address: " << passenger.address << "}";
    return os;
}

bool Passenger::operator==(const Passenger &rhs) const {
    return firstName == rhs.firstName &&
           lastName == rhs.lastName &&
           id == rhs.id &&
           address == rhs.address;
}

bool Passenger::operator!=(const Passenger &rhs) const {
    return !(rhs == *this);
}