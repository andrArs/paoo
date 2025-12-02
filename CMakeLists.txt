cmake_minimum_required(VERSION 3.10)

project(RestaurantApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

include_directories(inc)

set(SOURCES
    src/main.cpp
    src/RecipeBook.cpp
    src/Order.cpp
    src/Microphone.cpp
    
    inc/RecipeBook.hpp
    inc/Order.hpp
    inc/Microphone.hpp
)

add_executable(RestaurantApp ${SOURCES})

target_link_libraries(RestaurantApp Threads::Threads)