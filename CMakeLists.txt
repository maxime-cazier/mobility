cmake_minimum_required(VERSION 3.4)
project("MOBILITY")
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Main main.cpp)
target_link_libraries(Main Imagine::Graphics)


