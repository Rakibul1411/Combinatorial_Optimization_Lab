cmake_minimum_required(VERSION 3.25)
project(Activity_Selection)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Activity_Selection
        activiti_selection.cpp)
