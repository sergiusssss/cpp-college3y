//
// Created by Serhii Pustovit on 10.09.2025.
//

#include <group.hpp>
#include <iostream>

namespace oop {
    Group::Group(){}


    std::int32_t Group::get_id(){
        return m_id;
    }

    void Group::set_id(std::int32_t id){
        m_id = id;
    }

    std::string Group::get_name(){
        return m_name;
    }

    void Group::set_name(const std::string& name){
        if (!name.empty()) {
            if (std::tolower(name[0]) == 'a') {
                std::cout << "Sorry, bro. You have a very strange name." << std::endl;
                return;
            }

            m_name = name;
        }
    }


    void Group::add_student(Student student){}
    void Group::show_info(){}

} // oop