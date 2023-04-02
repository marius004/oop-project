#include <utility>
#include <ctime>
#include <cmath>

#include "../headers/Aircraft.h"
#include "../headers/Utils.h"

Aircraft::Aircraft(std::string manufacturer, std::string model, int year, int capacity, time_t lastRevision)
        : manufacturer(std::move(manufacturer)), model(std::move(model)),
          year(year), capacity(capacity), lastRevision(lastRevision) {}



[[maybe_unused]] int Aircraft::getYear() const {
    return year;
}

int Aircraft::getCapacity() const {
    return capacity;
}

std::ostream &operator<<(std::ostream &os, const Aircraft &aircraft) {
    os << "Aircraft{" << "manufacturer: " << aircraft.manufacturer << " model: " << aircraft.model << " year: " << aircraft.year
       << " capacity: " << aircraft.capacity << " lastRevision: " << aircraft.lastRevision << "}";
    return os;
}

void Aircraft::maintenance(time_t time) {
    this->lastRevision = time;
}

bool Aircraft::operator==(const Aircraft &rhs) const {
    return manufacturer == rhs.manufacturer &&
           model == rhs.model &&
           year == rhs.year &&
           capacity == rhs.capacity &&
           lastRevision == rhs.lastRevision;
}

bool Aircraft::operator!=(const Aircraft &rhs) const {
    return !(rhs == *this);
}

bool Aircraft::canFly() const {
    return std::abs(this->lastRevision - 5) <= Utils::MAX_TIME_FLYING_WITHOUT_REVISION;
}
