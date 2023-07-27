project(sandbox)
cmake_minimum_required(VERSION 3.20)

set (CMAKE_CXX_STANDARD 20)

add_subdirectory(interfaceTarget)
add_subdirectory(privateTarget)
add_subdirectory(publicTarget)
add_subdirectory(publicTarget2)

add_executable(hello_world main.cpp)

target_link_libraries(hello_world interfaceTarget)
target_link_libraries(hello_world publicTarget)

add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/hello_world
    DEPENDS hello_world
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
