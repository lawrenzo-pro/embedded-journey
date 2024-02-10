cmake_minimum_required(VERSION 3.12)
set(PICO_SDK_PATH "/usr/share/pico-sdk")
set(PICO_BOARD "pico_w")

include(pico_sdk_import.cmake)
project(multicore_blink C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_compile_options( -Wall 
                     -Wno-format
                     -Wno-unused-function
                     -Wno-maybe-uninitialised)

add_executable(multicore_blink main.c)
target_link_libraries(multicore_blink pico_stdlib hardware_i2c)

pico_add_extra_outputs(multicore_blink)
