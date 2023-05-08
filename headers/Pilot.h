#ifndef OOP_PILOT_H
#define OOP_PILOT_H

#include "../headers/AircraftCrewMember.h"

class Pilot : public AircraftCrewMember {
private:
    std::string license;
    [[nodiscard]] std::string getLandingMessage(const std::string& destination) const;

public:
    Pilot(std::string id, std::string name, unsigned int salary, std::string license);

    [[nodiscard]] std::string introduce(std::string flightNumber, std::string city) const override;

    void prepareForLanding(std::string destination,
                           std::unordered_set<std::shared_ptr<Passenger>> passengers) const override;

    [[nodiscard]] std::shared_ptr<AircraftCrewMember> clone() const override;

    [[nodiscard]] bool canFly() const override;
};

#endif //OOP_PILOT_H
