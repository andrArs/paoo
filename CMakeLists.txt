cmake_minimum_required(VERSION 3.10)

project(Image)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/Image.cpp
    src/ColoredImage.cpp
)

add_executable(Image ${SOURCES})
