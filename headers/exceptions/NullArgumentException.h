#ifndef OOP_NULLARGUMENTEXCEPTION_H
#define OOP_NULLARGUMENTEXCEPTION_H

#include "InvalidArgumentException.h"
#include <string>

class NullArgumentException : public InvalidArgumentException {
public:
    explicit NullArgumentException(std::string argumentName);
};

#endif //OOP_NULLARGUMENTEXCEPTION_H
