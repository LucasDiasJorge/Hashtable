cmake_minimum_required(VERSION 3.30)
project(CPP)

set(CMAKE_CXX_STANDARD 20)

add_library(Hashtable STATIC hashtable.cpp)

add_executable(CPP main.cpp)

target_link_libraries(CPP PRIVATE Hashtable)