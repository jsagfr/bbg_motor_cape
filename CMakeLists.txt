cmake_minimum_required (VERSION 2.6)
project (motor_cape)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_library(motor_cape src/Channel.cpp src/DCMotor.cpp src/MotorBridgeCape.cpp)
set_property(TARGET motor_cape PROPERTY CXX_STANDARD 11)
set_property(TARGET motor_cape PROPERTY CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

target_link_libraries(motor_cape gpioc++ i2c++)
target_include_directories(motor_cape PUBLIC include)

