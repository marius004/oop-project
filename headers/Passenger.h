#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <ostream>

#include "../headers/Address.h"

class Passenger {
private:
    std::string firstName;
    std::string lastName;
public:
    const std::string &getLastName() const;

private:
    std::string id;

    unsigned int age;
    Address address;
    bool seatbeltFastened;
public:
    Passenger(std::string firstName, std::string lastName, std::string id, unsigned int age, Address address);

    bool operator==(const Passenger &rhs) const;

    bool operator!=(const Passenger &rhs) const;

    [[nodiscard]] bool isSeatbeltFastened() const;

    void setSeatbeltFastened(bool fastened);

    friend std::ostream &operator<<(std::ostream &os, const Passenger &passenger);
};

#endif //PASSENGER_H
