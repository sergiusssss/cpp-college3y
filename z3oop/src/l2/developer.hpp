//
// Created by Serhii Pustovit on 15.09.2025.
//

#pragma once

#include <employee.hpp>

namespace bnp {

class Developer : public Employee{
public:
    Developer();
    ~Developer();

    void work();
private:
    int* m_secret_knowledge;
};

}
