cmake_minimum_required(VERSION 3.30.0)
project(recurring-engine VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)

add_subdirectory(dependencies/utils)

add_executable(reengine source/main.cpp source/window.cpp source/program.cpp)
target_link_libraries(reengine PRIVATE recore regui)
target_include_directories(reengine PRIVATE include)
include_directories(include)
