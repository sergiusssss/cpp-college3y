//
// Created by Serhii Pustovit on 10.09.2025.
//

#pragma once

#include <cinttypes>
#include <string>
#include <vector>

#include <student.hpp>

namespace oop {

class Group {
public:
    Group();

    std::int32_t get_id();
    void set_id(std::int32_t id);

    std::string get_name();
    void set_name(const std::string& name);

    void add_student(Student student);
    void show_info();
private:
    std::int32_t m_id;
    std::string m_name;

    std::vector<Student> m_students;
};

} // oop
