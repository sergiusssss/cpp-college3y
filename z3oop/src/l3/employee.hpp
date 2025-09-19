//
// Created by Serhii Pustovit on 15.09.2025.
//

#pragma once

namespace bnp {

class Employee {
public:
    Employee();
    Employee(int data);

    Employee(const Employee& other);
    Employee& operator=(const Employee& other);

    Employee(Employee&& other);
    Employee& operator=(Employee&& other);

    ~Employee();

    void work();

private:
    int* m_data;
};

} // bnp

