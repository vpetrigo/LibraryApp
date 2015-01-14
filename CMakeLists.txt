cmake_minimum_required(VERSION 2.8.4)
project(Library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("../")
include_directories("${PROJECT_BINARY_DIR}")

add_library(Chrono Chrono.cpp)
add_library(Books Books.cpp)
add_library(Patron Patron.cpp)

set(SOURCE_FILES Test.cpp)
add_executable(Library ${SOURCE_FILES})
target_link_libraries(Library Books Chrono Patron)