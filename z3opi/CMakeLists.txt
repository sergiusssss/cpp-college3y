cmake_minimum_required(VERSION 3.30)
project(z3opi)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

include(FetchContent)

FetchContent_Declare (
        tracy
        GIT_REPOSITORY https://github.com/wolfpld/tracy.git
        GIT_TAG master
)
FetchContent_MakeAvailable(tracy)

target_link_libraries (${PROJECT_NAME} PUBLIC TracyClient)