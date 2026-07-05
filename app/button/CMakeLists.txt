
target_sources(${TARGET} PRIVATE
    src/button.cpp
)

target_include_directories(${TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/app/button/include
    ${CMAKE_SOURCE_DIR}/drivers/gpio/include
    ${CMAKE_SOURCE_DIR}/drivers/rcc/include
)