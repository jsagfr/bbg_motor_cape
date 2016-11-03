cmake_minimum_required (VERSION 2.6)
project (bbg_motor_cape)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_compile_options(-std=c++11)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_executable(bbg_motor_cape ${SOURCES})
