# Copyright 2023 Vincent Westenberg
# License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html

cmake_minimum_required(VERSION 3.10)

project(frogcon-server)

add_executable(frogcon-server
    src/main.cpp
    src/webservice.cpp
    src/webservice.h
)

target_link_libraries(frogcon-server fmt)

set_property(TARGET frogcon-server
    PROPERTY CXX_STANDARD 17
    PROPERTY CXX_STANDARD_REQUIRED
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(frogcon-server PRIVATE -Wall -Wextra -Wpedantic)
endif()
