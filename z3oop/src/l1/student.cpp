//
// Created by Serhii Pustovit on 10.09.2025.
//

#include <iostream>

#include <student.hpp>

namespace oop {

Student::Student(std::int32_t id, std::string name) {
    m_id = id;
    m_name = name;
}

std::int32_t Student::get_id(){
    return m_id;
}

void Student::set_id(std::int32_t id){
}

std::string Student::get_name(){
    return m_name;
}

void Student::set_name(const std::string& name){
    if (!name.empty()) {
        if (std::tolower(name[0]) == 'a') {
            std::cout << "Sorry, bro. You have a very strange name." << std::endl;
            return;
        }

        m_name = name;
    }
}

} // oop