#ifndef OOP_RANDOMADDRESSFACTORY_H
#define OOP_RANDOMADDRESSFACTORY_H

#include "../headers/AddressFactory.h"
#include <vector>
#include <string>

class RandomAddressFactory : public AddressFactory {
private:
    inline static std::vector<std::string> streets {"Strada Costea Racovita", "Strada Danes", "Bulevardul Tudor Vladimirescu", "Strada Mihail Kogalniceanu", "Strada Ion Ratiu", "Strada Vasile Goldis" };
    inline static std::vector<std::string> cities {"Bucuresti", "Timisoara", "Cluj", "Craiova", "Constanta", "Arad"};
    inline static std::vector<std::string> countries {"Romania"};

public:
    [[nodiscard]] Address create() const override;
};

#endif //OOP_RANDOMADDRESSFACTORY_H
