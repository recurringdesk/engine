cmake_minimum_required(VERSION 3.30.0)
project(untitledengine VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(untitledengine source/main.cpp
        source/window.cpp
        source/app.cpp)
target_link_libraries(untitledengine PUBLIC untitledutils)
target_include_directories(untitledengine PUBLIC include)