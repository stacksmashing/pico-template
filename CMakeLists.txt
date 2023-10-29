cmake_minimum_required(VERSION 3.13)
# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(hello_pio)
 
pico_sdk_init()

add_executable(hello_pio)

pico_generate_pio_header(hello_pio ${CMAKE_CURRENT_LIST_DIR}/hello.pio)

target_sources(hello_pio PRIVATE hello.c)

target_link_libraries(hello_pio PRIVATE
        pico_stdlib
        hardware_pio
        )

pico_add_extra_outputs(hello_pio)



# enable usb output, disable uart output
pico_enable_stdio_usb(hello_pio 1)
pico_enable_stdio_uart(hello_pio 0)
