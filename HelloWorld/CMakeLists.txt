cmake_minimum_required(VERSION 3.5)
project(Hello)

#set output folders
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#include
include_directories("${PROJECT_SOURCE_DIR}")

#get sources
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp" ) 

add_executable(Hello ${SOURCES})

