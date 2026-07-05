target_sources(${TARGET} PRIVATE
    src/main.cpp
)

target_include_directories(${TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/app/led/include
    ${CMAKE_SOURCE_DIR}/app/button/include
)

