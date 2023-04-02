#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <ostream>

#include "../headers/Address.h"

class Passenger {
private:
    std::string firstName;
    std::string lastName;
    std::string id;
    Address address;

public:
    Passenger(std::string firstName, std::string lastName, std::string id, Address address);

    [[maybe_unused]] [[nodiscard]]
    const std::string &getFirstName() const;

    [[maybe_unused]] [[nodiscard]]
    const std::string &getLastName() const;

    [[maybe_unused]] [[nodiscard]]
    const std::string &getId() const;

    bool operator==(const Passenger &rhs) const;

    bool operator!=(const Passenger &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Passenger &passenger);
};

#endif //PASSENGER_H
