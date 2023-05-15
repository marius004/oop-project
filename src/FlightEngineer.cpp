#include <utility>

#include "../headers/FlightEngineer.h"
#include <sstream>

FlightEngineer::FlightEngineer(std::string id, std::string name, unsigned int salary, int experience)
    : AircraftCrewMember(std::move(id), std::move(name),salary), experience(experience) {}

std::string FlightEngineer::introduce(const std::string &flightNumber, const std::string &city) const {
    std::stringstream ss;

    ss << "Ladies and gentlemen, this is your flight engineer, " << this->name << ", speaking.\n";
    ss << "I would like to welcome you aboard flight " << flightNumber << " to " << city << ".\n";
    ss << "I'll be responsible for monitoring and maintaining the aircraft's systems during the flight.\n";
    ss << "If you have any questions or concerns regarding the aircraft's systems, feel free to ask.\n";
    ss << "Thank you for choosing to fly with us today, and I hope you have a pleasant flight.\n";

    return ss.str();
}

void FlightEngineer::prepareForLanding(const std::string &destination,
                                       std::unordered_set<std::shared_ptr<Passenger>> passengers) const {
    std::cout << "Flight Engineer: Preparing for landing at " << destination << ".\n";

    int count = 0;
    for (const auto& passenger : passengers) {
        if (!passenger->isSeatbeltFastened())
            count++;
    }

    if (count == 0)
        std::cout << "Flight Engineer: Preparation for landing complete.\n";
    else
        std::cout << "Flight Engineer: The flight attendants will come to make sure you have fastened your seatbelts\n";
}

std::shared_ptr<AircraftCrewMember> FlightEngineer::clone() const {
    return std::make_shared<FlightEngineer>(id, name, salary, experience);
}

std::ostream &operator<<(std::ostream &os, const FlightEngineer &engineer) {
    os << static_cast<const AircraftCrewMember &>(engineer) << " experience: " << engineer.experience;
    return os;
}

