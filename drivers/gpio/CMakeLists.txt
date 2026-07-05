
target_sources(${TARGET} PRIVATE
    src/gpio.cpp
)

target_include_directories(${TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/drivers/gpio/include
    ${CMAKE_SOURCE_DIR}/drivers/rcc/include
    ${CMAKE_SOURCE_DIR}/lib/cmsis
    ${CMAKE_SOURCE_DIR}/lib/device
)