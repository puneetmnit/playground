cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_FLAGS "-std=c++14" )

#library
set(LIBRARY_NAME Algolib)

#get sources
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp" )

#add Library
add_library( ${LIBRARY_NAME} SHARED ${SOURCES} )


