#include <utility>

#include "../headers/Employee.h"

Employee::Employee(std::string  id, std::string  name, unsigned int salary)
    : id(std::move(id)), name(std::move(name)), salary(salary) {}

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << "id: " << employee.id << " name: " << employee.name << " salary: " << employee.salary;
    return os;
}

const std::string &Employee::getName() const {
    return name;
}

