#include "../../headers/exceptions/NullArgumentException.h"

NullArgumentException::NullArgumentException(const std::string& argumentName) :
    InvalidArgumentException("Argument " + argumentName + " cannot be null") {}
