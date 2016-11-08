cmake_minimum_required (VERSION 2.6)
project (motor_cape)

# include_directories(include)
# include_directories(${i2c++_SOURCE_DIR}/include)
# include_directories(${i2c++_BINARY_DIR})

# set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/.cpp)
file(GLOB SOURCES "src/*.cpp")

# add_subdirectory(i2cpp)
# include_directories(${CMAKE_SOURCE_DIR}/i2cpp/include)
# include_directories(${CMAKE_SOURCE_DIR}/i2cpp)


add_compile_options(-Wall)
add_compile_options(-Wextra)
add_library(motor_cape src/Channel.cpp src/DCMotor.cpp src/MotorBridgeCape.cpp)
set_property(TARGET motor_cape PROPERTY CXX_STANDARD 11)
set_property(TARGET motor_cape PROPERTY CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

target_link_libraries(motor_cape i2c++)
target_include_directories(motor_cape PUBLIC include)

