#ifndef OOP_RANDOMPASSENGERFACTORY_H
#define OOP_RANDOMPASSENGERFACTORY_H

#include "PassengerFactory.h"
#include "AddressFactory.h"
#include <memory>
#include <string>

class RandomPassengerFactory : public PassengerFactory {
private:
    inline static std::vector<std::string> firstNames = {"Popescu", "Birau", "Bratosin", "Horia", "Livia", "Alma", "Vicențiu", "Tania"};
    inline static std::vector<std::string> lastNames {"Alex", "Madalina", "Ciocirlan", "Calin", "Birsan", "Oana", "Nita"};
    inline static std::vector<std::string> streets {"Strada Costea Racovita", "Strada Danes", "Bulevardul Tudor Vladimirescu", "Strada Mihail Kogalniceanu", "Strada Ion Ratiu", "Strada Vasile Goldis" };
    inline static std::vector<std::string> cities {"Bucuresti", "Timisoara", "Cluj", "Craiova", "Constanta", "Arad"};
    inline static std::vector<std::string> countries {"Romania"};
    inline static std::vector<std::string> digits {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    std::shared_ptr<AddressFactory> addressFactory;
    static std::string generateID();
public:
    explicit RandomPassengerFactory(const std::shared_ptr<AddressFactory> &addressFactory);

    [[nodiscard]] std::shared_ptr<AircraftCrewMember> createCrewMember(bool pilot, const std::string &license) const override;
    [[nodiscard]] std::shared_ptr<Passenger> createPassenger(bool infant, const std::shared_ptr<Passenger> &caretaker) const override;
};

#endif //OOP_RANDOMPASSENGERFACTORY_H
