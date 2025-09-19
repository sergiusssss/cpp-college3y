cmake_minimum_required(VERSION 3.30)
project(${PROJECT_NAME}-l1)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        student.cpp
        group.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE .)
