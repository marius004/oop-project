#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <ctime>
#include <ostream>

class Aircraft {
private:
    std::string manufacturer;
    std::string model;

    int year;
    int capacity;
    std::time_t lastRevision;

public:
    Aircraft(std::string manufacturer, std::string model, int year, int capacity, time_t lastRevision);

    [[maybe_unused]] [[nodiscard]]
    const std::string &getManufacturer() const;

    [[maybe_unused]] [[nodiscard]]
    const std::string &getModel() const;

    [[maybe_unused]] [[nodiscard]]
    int getYear() const;

    [[nodiscard]]
    int getCapacity() const;

    [[maybe_unused]] [[nodiscard]]
    time_t getLastRevision() const;

    void maintenance(time_t time);

    [[nodiscard]]
    bool canFly() const;

    bool operator==(const Aircraft &rhs) const;

    bool operator!=(const Aircraft &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Aircraft &aircraft);
};

#endif //AIRCRAFT_H
