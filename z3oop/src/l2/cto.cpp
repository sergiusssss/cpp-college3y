//
// Created by Serhii Pustovit on 15.09.2025.
//

#include "cto.hpp"

#include <iostream>

namespace bnp {
    CTO::CTO() {
        std::cout << "CTO()" << std::endl;
    }

    CTO::~CTO() {
        std::cout << "~CTO()" << std::endl;
    }

    void CTO::work() {
        std::cout << "CTO work!" << std::endl;
    }
}