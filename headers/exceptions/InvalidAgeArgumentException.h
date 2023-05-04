#ifndef OOP_INVALIDAGEARGUMENTEXCEPTION_H
#define OOP_INVALIDAGEARGUMENTEXCEPTION_H

#include "InvalidArgumentException.h"

class InvalidAgeArgumentException : public InvalidArgumentException {
private:
    unsigned int maxAge;
    unsigned int minAge;

public:
    explicit InvalidAgeArgumentException(unsigned int minAge = 0, unsigned int maxAge = INT_MAX);
};

#endif //OOP_INVALIDAGEARGUMENTEXCEPTION_H
