cmake_minimum_required(VERSION 3.20)

add_library(publicTarget2 publicTarget2.cpp)

target_include_directories(publicTarget2 PUBLIC ".")
