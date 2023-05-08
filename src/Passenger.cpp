#include <utility>
#include "../headers/Passenger.h"

Passenger::Passenger(std::string firstName, std::string lastName, std::string id, unsigned int age, Address address)
    : firstName(std::move(firstName)), lastName(std::move(lastName)),
    id(std::move(id)), age(age), address(std::move(address)), seatbeltFastened(false) {}

std::ostream &operator<<(std::ostream &os, const Passenger &passenger) {
    os << "Passenger{" << "firstName: " << passenger.firstName << " lastName: " << passenger.lastName << " id: "
       << passenger.id << " age: " << passenger.age << " address: " << passenger.address << "}";
    return os;
}

bool Passenger::operator==(const Passenger &rhs) const {
    return firstName == rhs.firstName &&
           lastName == rhs.lastName &&
           id == rhs.id &&
           age == rhs.age &&
           address == rhs.address;
}

bool Passenger::operator!=(const Passenger &rhs) const {
    return !(rhs == *this);
}

bool Passenger::isSeatbeltFastened() const {
    return seatbeltFastened;
}

void Passenger::setSeatbeltFastened(bool fastened) {
    this->seatbeltFastened = fastened;
}

const std::string &Passenger::getLastName() const {
    return lastName;
}
