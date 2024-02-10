cmake_minimum_required(VERSION 3.28)
set(PICO_SDK_PATH "/usr/share/pico-sdk")
set(PICO_BOARD "pico_w")
include(pico_sdk_import.cmake)
project(hello_pwm C CXX ASM)
pico_sdk_init()
add_executable(
    hello_pwm main.c
)
target_link_libraries(hello_pwm pico_stdlib hardware_pwm hardware_adc pico_multicore)
pico_enable_stdio_usb(hello_pwm 1)
pico_enable_stdio_uart(hello_pwm 0)
pico_add_extra_outputs(hello_pwm)