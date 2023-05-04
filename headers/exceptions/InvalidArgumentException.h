#ifndef OOP_INVALIDARGUMENTEXCEPTION_H
#define OOP_INVALIDARGUMENTEXCEPTION_H

#include <exception>
#include <string>

class InvalidArgumentException : public std::exception {
private:
    std::string message;

public:

    explicit InvalidArgumentException(std::string message);
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //OOP_INVALIDARGUMENTEXCEPTION_H
