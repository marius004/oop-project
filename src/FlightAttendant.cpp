#include "../headers/FlightAttendant.h"
#include <sstream>
#include <utility>
#include <memory>

FlightAttendant::FlightAttendant(std::string id, std::string name, unsigned int salary)
    : AircraftCrewMember(std::move(id), std::move(name), salary) {}

std::shared_ptr<AircraftCrewMember> FlightAttendant::clone() const {
    return std::make_shared<FlightAttendant>(id, name, salary);
}

std::string FlightAttendant::introduce(const std::string& flightNumber, const std::string& city) const {
    std::stringstream ss;

    ss << "Good afternoon, ladies and gentlemen. On behalf of the captain and the entire crew, I'd like to welcome you aboard flight ";
    ss << flightNumber << " to " << city << "\n";
    ss << "We are pleased to have you onboard and we hope you enjoy your flight with us today.\n";

    return ss.str();
}

void FlightAttendant::prepareForLanding(const std::string& destination,
                                        std::unordered_set<std::shared_ptr<Passenger>> passengers) const {
    std::stringstream ss;

    ss << "Good afternoon, ladies and gentlemen. As we begin our descent into" << destination << ",\n";
    ss << "please return to your seats and ensure your seat belts are securely fastened. Please review the safety card in front ";
    ss << "of you and stow your tray tables. Thank you for choosing to fly with us today\n";

    std::cout << ss.str();

    for (auto& passenger : passengers)
        if (!passenger->isSeatbeltFastened())
            passenger->setSeatbeltFastened(true);
}

std::ostream &operator<<(std::ostream &os, const FlightAttendant &attendant) {
    os << static_cast<const AircraftCrewMember &>(attendant);
    return os;
}
