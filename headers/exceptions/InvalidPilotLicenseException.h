#ifndef OOP_INVALIDPILOTLICENSEEXCEPTION_H
#define OOP_INVALIDPILOTLICENSEEXCEPTION_H

#include <exception>
#include <cstring>
#include <string>

class InvalidPilotLicenseException : public std::exception {
private:
    std::string pilotName;
public:
    explicit InvalidPilotLicenseException(std::string pilotName);
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //OOP_INVALIDPILOTLICENSEEXCEPTION_H
