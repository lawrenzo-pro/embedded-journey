cmake_minimum_required(VERSION 3.28)
set(PICO_SDK_PATH "/home/lawrence/pico-sdk")
set(PICO_BOARD "pico_w")
include(pico_sdk_import.cmake)
project(fade_led C CXX ASM)
pico_sdk_init()
add_executable(
    fade_led fade_led.c
)
target_link_libraries(fade_led pico_stdlib hardware_pwm)
pico_add_extra_outputs(fade_led)