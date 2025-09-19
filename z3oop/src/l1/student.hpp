//
// Created by Serhii Pustovit on 10.09.2025.
//

#pragma once

#include <cinttypes>
#include <string>

namespace oop {

// class <CLASS NAME>
class Student {
public: // -> Available for everyone everywhere
    Student(std::int32_t id, std::string name);
    //~Student();

    std::int32_t get_id();
    void set_id(std::int32_t id);

    std::string get_name();
    void set_name(const std::string& name);

private:
    std::int32_t m_id;
    std::string m_name;
};

} // oop
