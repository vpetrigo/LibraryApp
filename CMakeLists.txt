cmake_minimum_required(VERSION 2.8.4)
project(Library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("../")

add_library(Chrono Chrono.cpp)
add_library(Books Books.cpp)

set(SOURCE_FILES Test.cpp)
set(HEADER_FILES Books.h Chrono.h)
add_executable(Library ${SOURCE_FILES})
target_link_libraries(Library Books Chrono)