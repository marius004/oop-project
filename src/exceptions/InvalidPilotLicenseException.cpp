#include "../../headers/exceptions/InvalidPilotLicenseException.h"
#include <cstring>

const char *InvalidPilotLicenseException::what() const noexcept {
    std::string message = "Invalid license for pilot " + pilotName;
    return strdup(message.c_str());
}

InvalidPilotLicenseException::InvalidPilotLicenseException(std::string pilotName) :
    pilotName(std::move(pilotName)) {}
