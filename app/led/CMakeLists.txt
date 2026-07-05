
target_sources(${TARGET} PRIVATE
    src/led.cpp
)

target_include_directories(${TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/app/led/include
    ${CMAKE_SOURCE_DIR}/drivers/gpio/include
)
