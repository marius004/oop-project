#include "../../headers/exceptions/NullArgumentException.h"

NullArgumentException::NullArgumentException(std::string argumentName) :
    InvalidArgumentException("Argument " + argumentName + " cannot be null") {}
