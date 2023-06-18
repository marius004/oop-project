#ifndef OOP_EMPLOYEE_H
#define OOP_EMPLOYEE_H

#include <string>
#include <ostream>

class Employee {
protected:
    std::string id;
    std::string name;
    unsigned int salary;

public:
    Employee(std::string  id, std::string  name, unsigned int salary);
    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
    const std::string &getName() const;
};

#endif //OOP_EMPLOYEE_H
