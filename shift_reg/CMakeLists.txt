cmake_minimum_required(VERSION 3.28)
set(PICO_SDK_PATH "/home/lawrence/pico-sdk")
set(PICO_BOARD "pico_w")

include(pico_sdk_import.cmake)
project(shift_reg C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

#Dirty hack...
add_compile_options(-Wall
        -Wno-format          
        -Wno-unused-function 
        -Wno-maybe-uninitialized
)
add_executable(shift_reg shift_reg.c)
target_link_libraries(shift_reg pico_stdlib pico_multicore pico_rand)
pico_enable_stdio_usb(shift_reg 1)
pico_enable_stdio_uart(shift_reg 0)
pico_add_extra_outputs(shift_reg)
