//
// Created by Serhii Pustovit on 15.09.2025.
//

#pragma once

#include "employee.hpp"

namespace bnp {

class CEO : public Employee{
public:
    CEO();
    ~CEO();

    void work();
};

} // bnp
