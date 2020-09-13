cmake_minimum_required(VERSION 3.5)

project(taskE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taskE main.cpp solution_tree.h my_solution.cpp)
