#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

class Address {
private:

    std::string street;
    std::string city;
    std::string country;

public:

    [[maybe_unused]]
    Address(std::string  street, std::string city, std::string country);

    [[maybe_unused]] [[nodiscard]]
    const std::string &getStreet() const;

    [[maybe_unused]] [[nodiscard]]
    const std::string &getCity() const;

    [[maybe_unused]] [[nodiscard]]
    const std::string &getCountry() const;

    bool operator==(const Address &rhs) const;
    bool operator!=(const Address &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Address &address);
};

#endif //ADDRESS_H
