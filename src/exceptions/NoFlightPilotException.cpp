#include <utility>
#include <cstring>

#include "../../headers/exceptions/NoFlightPilotException.h"

const char *NoFlightPilotException::what() const noexcept {
    auto message = std::string("No pilot for flight " + flightNumber);
    return strdup(message.c_str());
}

NoFlightPilotException::NoFlightPilotException(std::string flightNumber)
    : flightNumber(std::move(flightNumber)) {}
