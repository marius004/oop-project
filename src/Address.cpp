#include <utility>
#include "../headers/Address.h"

Address::Address(std::string street, std::string city, std::string country)
    : street(std::move(street)), city(std::move(city)), country(std::move(country)) {}

bool Address::operator==(const Address &rhs) const {
    return this->street == rhs.street &&
           this->city == rhs.city &&
           this->country == rhs.country;
}

bool Address::operator!=(const Address &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Address &address) {
    os << "Address{" << "street: " << address.street << " city: " << address.city << " country: " << address.country << "}";
    return os;
}
