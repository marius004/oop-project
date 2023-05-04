#include "../headers/exceptions/InvalidAgeArgumentException.h"
#include "../headers/exceptions/NullArgumentException.h"
#include "../headers/InfantPassenger.h"

InfantPassenger::InfantPassenger(const std::string &firstName, const std::string &lastName,
                                 const std::string &id, unsigned int age, const Address &address,
                                 const std::shared_ptr<Passenger>& caretaker)
         : Passenger(firstName, lastName, id, age, address), caretaker(caretaker) {
    if (caretaker == nullptr) throw NullArgumentException("caretaker");
    if (age > 2) throw InvalidAgeArgumentException(0, 2);
}
