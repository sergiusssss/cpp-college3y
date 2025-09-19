//
// Created by Serhii Pustovit on 15.09.2025.
//

#include "employee.hpp"

#include <iostream>
#include <ostream>

namespace bnp {
    Employee::Employee() {
        std::cout << "Employee()" << std::endl;
    }

    Employee::~Employee() {
        std::cout << "~Employee()" << std::endl;
    }

    void Employee::work() {
    std::cout << "Employee work!" << std::endl;
}


} // bnp