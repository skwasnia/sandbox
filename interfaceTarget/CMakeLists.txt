cmake_minimum_required(VERSION 3.20)

add_library(interfaceTarget INTERFACE)

target_sources(interfaceTarget INTERFACE interfaceTarget.cpp)

target_include_directories(interfaceTarget INTERFACE ".")
