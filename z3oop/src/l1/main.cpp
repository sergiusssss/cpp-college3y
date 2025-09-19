#include <iostream>

#include <student.hpp>
#include <group.hpp>

int main() {
    oop::Student student(123321, "Vadim");

    std::cout << student.get_id() << " -- " << student.get_name() << std::endl;

    oop::Group group;
    group.set_id(121342);
    group.set_name("Z-32");
    std::cout << group.get_id() << " -- " << group.get_name() << std::endl;

}
