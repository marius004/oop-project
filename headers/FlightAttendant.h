#ifndef OOP_FLIGHTATTENDANT_H
#define OOP_FLIGHTATTENDANT_H

#include "../headers/AircraftCrewMember.h"

class FlightAttendant : public AircraftCrewMember {
public:
    FlightAttendant(std::string id, std::string name, unsigned int salary);

    [[nodiscard]] std::string introduce(std::string flightNumber, std::string city) const override;

    void prepareForLanding(std::string destination,
                           std::unordered_set<std::shared_ptr<Passenger>> passengers) const override;

    [[nodiscard]] std::shared_ptr<AircraftCrewMember> clone() const override;

    bool canFly() const override;
};

#endif //OOP_FLIGHTATTENDANT_H