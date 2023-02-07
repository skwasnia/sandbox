cmake_minimum_required(VERSION 3.20)

add_library(privateTarget privateTarget.cpp)

target_include_directories(privateTarget PUBLIC ".")
