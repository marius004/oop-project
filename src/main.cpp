#include <utility>
#include <vector>
#include <string>
#include <ctime>
#include <ostream>
#include <iostream>

class Address {
private:
    std::string street;
    std::string city;
    std::string country;

    unsigned int postalCode;

public:

    [[maybe_unused]]
    Address(std::string  street, std::string city, std::string country, unsigned int postalCode)
            : street(std::move(street)), city(std::move(city)), country(std::move(country)), postalCode(postalCode) {}

    Address() = default;

    [[nodiscard]]
    const std::string &getStreet() const {
        return street;
    }

    [[nodiscard]]
    const std::string &getCity() const {
        return city;
    }

    [[nodiscard]]
    const std::string &getCountry() const {
        return country;
    }

    [[nodiscard]]
    unsigned int getPostalCode() const {
        return postalCode;
    }

    bool operator==(const Address &rhs) const {
        return this->street == rhs.street &&
               this->city == rhs.city &&
               this->country == rhs.country &&
               this->postalCode == rhs.postalCode;
    }

    bool operator!=(const Address &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " country: " << address.country
           << " postalCode: " << address.postalCode;
        return os;
    }
};

class Flight {
private:
    std::string flightNumber;
    Address departure;
    Address arrival;
    std::time_t duration;

public:
    Flight(std::string flightNumber, Address departure, Address arrival, time_t duration)
            : flightNumber(std::move(flightNumber)), departure(std::move(departure)),
            arrival(std::move(arrival)), duration(duration) {}

    Flight(const Flight& flight)
        : flightNumber(flight.flightNumber), departure(flight.departure),
        arrival(flight.arrival), duration(flight.duration) {}

    [[maybe_unused]]
    [[nodiscard]]
    const std::string &getFlightNumber() const {
        return flightNumber;
    }

    [[maybe_unused]]
    [[nodiscard]]
    Address getDeparture() const {
        return departure;
    }

    [[maybe_unused]]
    [[nodiscard]]
    Address getArrival() const {
        return arrival;
    }

    [[maybe_unused]]
    [[nodiscard]]
    time_t getDuration() const {
        return duration;
    }

    [[maybe_unused]]
    Flight delay(std::time_t delay) {
        Flight delayedFlight = Flight(*this);
        delayedFlight.duration += delay;
        return delayedFlight;
    }

    bool operator==(const Flight &rhs) const {
        return this->flightNumber == rhs.flightNumber &&
               this->departure == rhs.departure &&
               this->arrival == rhs.arrival &&
               this->duration == rhs.duration;
    }

    bool operator!=(const Flight &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Flight &flight) {
        os << "flightNumber: " << flight.flightNumber << " departure: " << flight.departure << " arrival: "
           << flight.arrival << " duration: " << flight.duration;
        return os;
    }

    Flight& operator=(const Flight& other) = default;

    ~Flight() {
        std::cout << "~Flight()" << "\n";
    }
};


class Airport {
private:
    std::string name;
    std::string code;

    Address address;
    std::vector<Flight> flights;

public:
    Airport(std::string  name, Address address, std::string code, const std::vector<Flight> &flights = {})
            : name(std::move(name)), code(std::move(code)), address(std::move(address)), flights(flights) {}

    Airport() = default;

    [[nodiscard]]
    const std::string &getName() const {
        return name;
    }

    [[nodiscard]]
    const std::string &getCode() const {
        return code;
    }

    [[nodiscard]]
    const Address &getAddress() const {
        return address;
    }

    [[nodiscard]]
    const std::vector<Flight> &getFlights() const {
        return flights;
    }

    [[nodiscard]]
    bool addFlight(const Flight& newFlight) {
        for (const auto& flight : this->flights)
            if (flight == newFlight)
                return false;

        this->flights.emplace_back(newFlight);
        return true;
    }

    bool operator==(const Airport &rhs) const {
        return this->name == rhs.name &&
               this->code == rhs.code &&
               this->address == rhs.address;
    }

    bool operator!=(const Airport &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Airport &airport) {
        os << "name: " << airport.name << " code: " << airport.code << " address: " << airport.address << " flights: ";
        return os;
    }
};

class Aircraft {
private:
    std::string name;
    std::string model;

    std::vector<Flight> flights;
    unsigned int manufacturingYear;

public:
    Aircraft(std::string name, std::string model, unsigned int manufacturingYear, const std::vector<Flight> &flights = {})
            : name(std::move(name)), model(std::move(model)), flights(flights), manufacturingYear(manufacturingYear) {}

    [[nodiscard]]
    const std::string &getName() const {
        return name;
    }

    [[nodiscard]]
    const std::string &getModel() const {
        return model;
    }

    [[nodiscard]]
    const std::vector<Flight> &getFlights() const {
        return flights;
    }

    [[nodiscard]]
    unsigned int getManufacturingYear() const {
        return manufacturingYear;
    }

    friend std::ostream &operator<<(std::ostream &os, const Aircraft &aircraft) {
        os << "name: " << aircraft.name << " model: " << aircraft.model << " manufacturingYear: "
           << aircraft.manufacturingYear;
        return os;
    }
};

class Airline {
private:
    std::string name;
    std::string code;

    std::vector<Flight> flights;
    std::vector<Aircraft> aircraft;
public:
    Airline(std::string name, std::string code, const std::vector<Flight> &flights = {}, const std::vector<Aircraft> &aircraft = {})
        : name(std::move(name)), code(std::move(code)), flights(flights), aircraft(aircraft) {}

    [[nodiscard]]
    const std::string &getName() const {
        return name;
    }

    [[nodiscard]]
    const std::string &getCode() const {
        return code;
    }

    [[nodiscard]]
    const std::vector<Flight> &getFlights() const {
        return flights;
    }

    bool addFlight(const Flight& newFlight) {
        for (const auto& flight : this->flights)
            if (flight == newFlight)
                return false;

        this->flights.emplace_back(newFlight);
        return true;
    }

    void addAircraft(const Aircraft& newAircraft) {
        this->aircraft.emplace_back(newAircraft);
    }

    bool cancelFlight(const Flight& cancelledFlight) {
        auto iterator = std::remove(this->flights.begin(), this->flights.end(), cancelledFlight);
        return iterator != this->flights.end();
    }

    friend std::ostream &operator<<(std::ostream &os, const Airline &airline) {
        os << "name: " << airline.name << " code: " << airline.code;
        return os;
    }
};

int main() {

    return 0;
}
