cmake_minimum_required(VERSION 3.5)

project(taskB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taskB main.cpp solution_tree.h my_solution.cpp)
