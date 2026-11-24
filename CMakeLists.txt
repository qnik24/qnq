cmake_minimum_required(VERSION 4.0)
project("qnq"
    DESCRIPTION "qnik's Quake Clone"
    LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/lib")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# compile dependencies
add_subdirectory(libs/glfw)

add_subdirectory(code)
