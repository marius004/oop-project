#ifndef OOP_FLIGHTATTENDANT_H
#define OOP_FLIGHTATTENDANT_H

#include "../headers/AircraftCrewMember.h"

class FlightAttendant : public AircraftCrewMember {
public:
    FlightAttendant(std::string id, std::string name, unsigned int salary);

    [[nodiscard]] std::string introduce(const std::string& flightNumber, const std::string& city) const override;

    void prepareForLanding(const std::string& destination,
                           std::vector<std::shared_ptr<Passenger>> passengers) const override;

    [[nodiscard]] std::shared_ptr<AircraftCrewMember> clone() const override;

    [[nodiscard]] bool canFly() const override;
};

#endif //OOP_FLIGHTATTENDANT_H
