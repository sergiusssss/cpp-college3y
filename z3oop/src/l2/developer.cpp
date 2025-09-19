//
// Created by Serhii Pustovit on 15.09.2025.
//

#include "developer.hpp"

#include <iostream>

namespace bnp {
    Developer::Developer() {
        std::cout << "Developer()" << std::endl;
    }

    Developer::~Developer() {
        std::cout << "~Developer()" << std::endl;
    }

    void Developer::work() {
        std::cout << "Developer work!" << std::endl;
    }
}