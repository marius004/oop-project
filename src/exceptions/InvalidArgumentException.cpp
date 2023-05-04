#include <utility>

#include "../../headers/exceptions/InvalidArgumentException.h"

const char *InvalidArgumentException::what() const noexcept {
    return message.c_str();
}

InvalidArgumentException::InvalidArgumentException(std::string message) : message(std::move(message)) {}