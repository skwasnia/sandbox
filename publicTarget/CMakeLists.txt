cmake_minimum_required(VERSION 3.20)

add_library(publicTarget publicTarget.cpp)

target_include_directories(publicTarget PUBLIC ".")

target_link_libraries(publicTarget PRIVATE privateTarget)
target_link_libraries(publicTarget PUBLIC publicTarget2)
