cmake_minimum_required(VERSION 3.4)
project(Algorithms)

set(CMAKE_CXX_FLAGS "-std=c++14" )

#set output folders
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#library 

set(LIBRARY_NAME Algolib)
set(LIBRARY_PATH AlgoLib)

#include
include_directories("${PROJECT_SOURCE_DIR}")
add_subdirectory(${LIBRARY_PATH})

#find_package(${LIBRARY_NAME} REQUIRED)

#get sources
file(GLOB SOURCES RELATIVE ${PROJECT_SOURCE_DIR} "*.cpp" ) 

foreach(source ${SOURCES})
    string(REPLACE ".cpp" "" exename ${source}) 
    add_executable( ${exename} ${source} )
    target_link_libraries( ${exename} ${LIBRARY_NAME})
endforeach(source ${SOURCES})

