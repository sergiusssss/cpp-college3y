//
// Created by Serhii Pustovit on 15.09.2025.
//

#include "ceo.hpp"

#include <iostream>

namespace bnp {
    CEO::CEO() {
        std::cout << "CEO()" << std::endl;
    }

    CEO::~CEO() {
        std::cout << "~CEO()" << std::endl;
    }

    void CEO::work() {
        std::cout << "CEO work!" << std::endl;
    }
} // bnp