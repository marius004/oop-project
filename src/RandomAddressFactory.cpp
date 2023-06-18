#include "../headers/RandomAddressFactory.h"

Address RandomAddressFactory::create() const {
    auto street = RandomAddressFactory::streets.at((rand() % RandomAddressFactory::streets.size()));
    auto city = RandomAddressFactory::cities.at(rand() % RandomAddressFactory::cities.size());
    auto country = RandomAddressFactory::countries.at(rand() % RandomAddressFactory::countries.size());

    return {street, city, country};
}
