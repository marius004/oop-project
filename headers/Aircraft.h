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

    [[nodiscard]] int getCapacity() const;

    [[nodiscard]] bool canFly() const;

    void maintenance(time_t time);

    bool operator==(const Aircraft &rhs) const;

    bool operator!=(const Aircraft &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Aircraft &aircraft);
};

#endif //AIRCRAFT_H
