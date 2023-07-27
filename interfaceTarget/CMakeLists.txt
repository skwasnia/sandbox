cmake_minimum_required(VERSION 3.20)

cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME TARGET_NAME)

add_library(${TARGET_NAME} INTERFACE)
target_sources(${TARGET_NAME} INTERFACE ${TARGET_NAME}.cpp)
target_include_directories(${TARGET_NAME} INTERFACE ".")
