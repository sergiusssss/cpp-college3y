//
// Created by Serhii Pustovit on 15.09.2025.
//

#include "employee.hpp"

#include <iostream>
#include <ostream>

namespace bnp {
    Employee::Employee() {
        std::cout << "Employee()" << std::endl;
        m_data = new int[4];
        m_data[0] = 0;
        m_data[1] = 0;
        m_data[2] = 0;
        m_data[3] = 0;
    }

    Employee::Employee(int data) {
        std::cout << "Employee(int)" << std::endl;

        m_data = new int[4];
        m_data[0] = data;
        m_data[1] = data;
        m_data[2] = data;
        m_data[3] = data;
    }

    Employee::Employee(const Employee &other) {
        std::cout << "Employee(const Employee &)" << std::endl;

        m_data = new int[4];
        m_data[0] = other.m_data[0];
        m_data[1] = other.m_data[1];
        m_data[2] = other.m_data[2];
        m_data[3] = other.m_data[3];
    }

    Employee & Employee::operator=(const Employee &other) {
        std::cout << "Employee::operator=(const Employee &)" << std::endl;

        if (this == &other) {
            return *this;
        }

        m_data = new int[4];
        m_data[0] = other.m_data[0];
        m_data[1] = other.m_data[1];
        m_data[2] = other.m_data[2];
        m_data[3] = other.m_data[3];

        return *this;
    }

    Employee::Employee(Employee &&other) {
        std::cout << "Employee(Employee &&)" << std::endl;

        m_data = other.m_data;
        other.m_data = nullptr;
    }

    Employee & Employee::operator=(Employee &&other) {
        std::cout << "Employee::operator=(Employee &&)" << std::endl;

        if (this == &other) {
            return *this;
        }

        m_data = other.m_data;
        other.m_data = nullptr;

        return *this;
    }

    Employee::~Employee() {
        std::cout << "~Employee() " << m_data << std::endl;
        delete[] m_data;
    }

    void Employee::work() {
        std::cout << "Employee work! " << m_data[0] << std::endl;
    }

} // bnp