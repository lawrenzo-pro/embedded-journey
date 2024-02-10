cmake_minimum_required(VERSION 3.12)
set(PICO_SDK_PATH "/usr/share/pico-sdk/")
set(PICO_BOARD "pico_w")
include(pico_sdk_import.cmake)
project(timer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

#Dirty hack...
add_compile_options(-Wall
        -Wno-format          
        -Wno-unused-function 
        -Wno-maybe-uninitialized
)

add_executable(timer ./src/main.c)
target_link_libraries(timer pico_stdlib pico_multicore)
pico_enable_stdio_usb(timer 1)
pico_enable_stdio_uart(timer 0)
pico_add_extra_outputs(timer)
