#ifndef OOP_NOFLIGHTPILOTEXCEPTION_H
#define OOP_NOFLIGHTPILOTEXCEPTION_H

#include <exception>
#include <string>

class NoFlightPilotException : public std::exception {
private:
    std::string flightNumber;
public:
    explicit NoFlightPilotException(std::string flightNumber);
    [[nodiscard]] const char* what() const noexcept override;
};


#endif //OOP_NOFLIGHTPILOTEXCEPTION_H
