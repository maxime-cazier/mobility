cmake_minimum_required(VERSION 3.4)
project("MOBILITY")
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Main pieton.h pieton.cpp util.h util.cpp obstacle.h obstacle.cpp main.cpp Direction.cpp Direction.h)
target_link_libraries(Main Imagine::Graphics)


