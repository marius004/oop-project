#ifndef OOP_ADDRESSFACTORY_H
#define OOP_ADDRESSFACTORY_H

#include "../headers/Address.h"

class AddressFactory {
public:
    virtual Address create() const = 0;
    virtual ~AddressFactory() = default;
};

#endif //OOP_ADDRESSFACTORY_H
