#ifndef OOP_EMPLOYEE_H
#define OOP_EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string id;
    std::string name;
    unsigned int salary;
public:
    Employee(std::string id, std::string name, unsigned int salary);
};

#endif //OOP_EMPLOYEE_H
