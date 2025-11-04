cmake_minimum_required(VERSION 3.10)
project(Person)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Person
    src/main.cpp
    src/Person.cpp
)

target_include_directories(Person PRIVATE src)

set_target_properties(Person PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)