#include <iostream>

#include <developer.hpp>

#include "ceo.hpp"
#include "cto.hpp"

int main() {
    std::vector<bnp::Employee*> employees;

    employees.push_back(new bnp::Developer());
    employees.push_back(new bnp::Developer());
    employees.push_back(new bnp::Developer());
    employees.push_back(new bnp::Developer());
    employees.push_back(new bnp::Developer());
    employees.push_back(new bnp::CTO());
    employees.push_back(new bnp::CEO());

    for (auto* employee : employees) {
        employee->work();
    }

    for (auto* employee : employees) {
        delete employee;
    }
    employees.clear();
}
