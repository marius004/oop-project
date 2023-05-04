#include "../../headers/exceptions/InvalidAgeArgumentException.h"

InvalidAgeArgumentException::InvalidAgeArgumentException(unsigned int minAge, unsigned int maxAge)
    : InvalidArgumentException("The age should be between " + std::to_string(minAge) + " and " + std::to_string(maxAge)),
      minAge(minAge), maxAge(maxAge) {}