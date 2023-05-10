#include <utility>

#include "../headers/Pilot.h"
#include <sstream>
#include <iostream>

Pilot::Pilot(const std::string& id, const std::string& name, unsigned int salary, std::string  license)
    : AircraftCrewMember(id, name, salary), license(std::move(license)) {}

std::string Pilot::getLandingMessage(const std::string& destination) const {
    std::stringstream ss;

    ss << "Good afternoon, ladies and gentlemen.\n";
    ss << "This is your captain, " << this->name << ", speaking.\n";

    ss << "As we begin our descent into " << destination << ", ";
    ss << "I would like to remind you to return to your seats and ensure that your seat belts are securely fastened.\n";
    ss << "We'll be landing shortly and the flight attendants will be coming through the cabin to collect any remaining cups or glasses.\n";
    ss << "Please ensure that all electronic devices are turned off and stowed at this time.\n";
    ss << "Thank you for flying with us today and we hope you had a pleasant flight.\n";

    return ss.str();
}

std::shared_ptr<AircraftCrewMember> Pilot::clone() const {
    return std::make_shared<Pilot>(id, name, salary, license);
}

std::string Pilot::introduce(const std::string& flightNumber, const std::string& city) const {
    std::stringstream ss;

    ss << "Good afternoon, ladies and gentlemen.\n";
    ss << "This is your captain, " << this->name << ", speaking.\n";

    ss << "I would like to take this opportunity to welcome you aboard flight " << flightNumber << " ";
    ss << "to " << city << "\n";

    ss << "I encourage you to sit back, relax and enjoy the flight\n";
    ss << "Our flight today will take approximately " << city << " minutes\n";
    ss << "Thank you for choosing to fly with us today and we'll speak with you again before we begin our descent into " << city << "\n";

    return ss.str();
}

void Pilot::prepareForLanding(const std::string& destination, std::vector<std::shared_ptr<Passenger>> passengers) const {
    std::cout << getLandingMessage(destination) << "\n";

    for (const auto& passenger : passengers)
        if (!passenger->isSeatbeltFastened())
            std::cout << "Plase fasten your seatbelt " << passenger.get()->getLastName() << "\n";
}


bool Pilot::canFly() const {
    return license != "";
}
