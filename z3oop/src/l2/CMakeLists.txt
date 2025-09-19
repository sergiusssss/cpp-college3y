cmake_minimum_required(VERSION 3.30)
project(${PROJECT_NAME}-l2)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        employee.cpp
        employee.hpp
        ceo.cpp
        ceo.hpp
        cto.cpp
        cto.hpp
        developer.cpp
        developer.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE .)
