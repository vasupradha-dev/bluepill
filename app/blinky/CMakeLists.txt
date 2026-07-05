
target_sources(${TARGET} PRIVATE
    src/blinky.cpp
)

target_include_directories(${TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/cmsis
    ${CMAKE_SOURCE_DIR}/lib/device
    ${CMAKE_SOURCE_DIR}/app/blinky/include
)
