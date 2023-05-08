#include "../../headers/exceptions/InvalidArgumentException.h"
#include <utility>
#include <cstring>

const char *InvalidArgumentException::what() const noexcept {
    return strdup(message.c_str());
}

InvalidArgumentException::InvalidArgumentException(std::string message) : message(std::move(message)) {}