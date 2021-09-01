# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "$ENV{PICO_SDK_PATH}")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(LED_Spectrum_Analyzer C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(LED_Spectrum_Analyzer LED_Spectrum_Analyzer.cpp CLI.c )

pico_set_program_name(LED_Spectrum_Analyzer "LED_Spectrum_Analyzer")
pico_set_program_version(LED_Spectrum_Analyzer "0.1")

pico_enable_stdio_uart(LED_Spectrum_Analyzer 1)
pico_enable_stdio_usb(LED_Spectrum_Analyzer 1)

# Add the standard library to the build
target_link_libraries(LED_Spectrum_Analyzer pico_stdlib)

pico_add_extra_outputs(LED_Spectrum_Analyzer)

