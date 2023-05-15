#ifndef OOP_FLIGHTENGINEER_H
#define OOP_FLIGHTENGINEER_H

#include "../headers/AircraftCrewMember.h"
#include <memory>

class FlightEngineer : public AircraftCrewMember {
public:
    FlightEngineer(std::string id, std::string name, unsigned int salary);

    [[nodiscard]] std::string introduce(const std::string &flightNumber, const std::string &city) const override;
    void prepareForLanding(const std::string &destination,
                           std::unordered_set<std::shared_ptr<Passenger>> passengers) const override;
    [[nodiscard]] std::shared_ptr<AircraftCrewMember> clone() const override;
};

#endif //OOP_FLIGHTENGINEER_H
