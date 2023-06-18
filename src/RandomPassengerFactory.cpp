#include "../headers/RandomPassengerFactory.h"
#include "../headers/FlightAttendant.h"
#include "../headers/InfantPassenger.h"
#include "../headers/Utils.h"

std::string RandomPassengerFactory::generateID() {
    std::string id = "";
    for (int i = 0;i < Utils::ID_LENGTH;++i)
        id += RandomPassengerFactory::digits.at(rand() % RandomPassengerFactory::digits.size());

    return  id;
}

std::shared_ptr<Passenger> RandomPassengerFactory::createPassenger(bool infant, const std::shared_ptr<Passenger> &caretaker) const {
    auto firstName = RandomPassengerFactory::firstNames.at(rand() % RandomPassengerFactory::firstNames.size());
    auto lastName = RandomPassengerFactory::lastNames.at(rand() % RandomPassengerFactory::lastNames.size());
    auto id = RandomPassengerFactory::generateID();
    // added an age offset so that a normal passenger(not infant) should be at least 2yo
    unsigned int age = (infant ? 0 : 2) + rand() % (infant ? 2 : 90);

    auto address = addressFactory->create();
    return infant ? std::make_shared<InfantPassenger>(firstName, lastName, id, age, address, caretaker)
                  : std::make_shared<Passenger>(firstName, lastName, id, age, address);
}

std::shared_ptr<AircraftCrewMember> RandomPassengerFactory::createCrewMember(bool pilot, const std::string &license) const {
    auto id = RandomPassengerFactory::generateID();
    auto name = RandomPassengerFactory::lastNames.at(rand() % RandomPassengerFactory::lastNames.size());
    unsigned int salary = (pilot ? 100'000 : 60'000) + rand() % (pilot ? 40'000 : 20'000);

    if (pilot)
        return std::make_shared<Pilot>(id, name, salary, license);

    return std::make_shared<FlightAttendant>(id, name, salary);
}

RandomPassengerFactory::RandomPassengerFactory(const std::shared_ptr<AddressFactory> &addressFactory)
        : addressFactory(addressFactory) {}
