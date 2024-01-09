cmake_minimum_required(VERSION 3.10)

project(Tessellate)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable
add_executable(Tessellate src/main.cpp)
