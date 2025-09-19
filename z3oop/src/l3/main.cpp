#include <iostream>

#include <employee.hpp>

int main() {
    bnp::Employee employee2{4};
    bnp::Employee employee3{5};

    employee2.work();

    bnp::Employee employee4{std::move(employee2)};

    employee4.work();
    //employee2.work();

    employee4 = std::move(employee3);

    employee4.work();

    //int a = 5;

    //std::move(a);
}
