#ifndef OOP_INFANTPASSENGER_H
#define OOP_INFANTPASSENGER_H

#include "Passenger.h"
#include <memory>

class InfantPassenger : public Passenger {
private:
    std::shared_ptr<Passenger> caretaker;

public:
    InfantPassenger(const std::string &firstName, const std::string &lastName,
                    const std::string &id, unsigned int age, const Address &address,
                    const std::shared_ptr<Passenger>& caretaker);
};

#endif //OOP_INFANTPASSENGER_H
