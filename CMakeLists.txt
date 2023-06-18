cmake_minimum_required(VERSION 3.24)
project(saper)

set(PROJECT_ID saper)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/saper.cpp
        )

add_executable(saper main.cpp include/saper.hpp src/saper.cpp)
