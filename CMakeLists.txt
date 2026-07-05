cmake_minimum_required(VERSION 3.22)

project(BluePill LANGUAGES C CXX ASM)

set(TARGET bluepill_fw)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# default if you don't pass -DCMAKE_BUILD_TYPE=...
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(${TARGET} app/main/src/main.cpp)

set_target_properties(${TARGET} PROPERTIES SUFFIX ".elf")

# main app
add_subdirectory(drivers)
add_subdirectory(app)

# startup file
target_sources(${TARGET} PRIVATE
    startup/stm32f103c8t6_startup.s
)

# linker
target_link_options(${TARGET} PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker/stm32f103c8t6.ld
    -nostartfiles
)

# post-build
find_program(ARM_OBJCOPY arm-none-eabi-objcopy REQUIRED)

add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND arm-none-eabi-size $<TARGET_FILE:${TARGET}>
    COMMAND arm-none-eabi-objcopy -O ihex   $<TARGET_FILE:${TARGET}> ${CMAKE_BINARY_DIR}/${TARGET}.hex
    COMMAND arm-none-eabi-objcopy -O binary $<TARGET_FILE:${TARGET}> ${CMAKE_BINARY_DIR}/${TARGET}.bin
)

# flash
set(OPENOCD_CFG ${CMAKE_SOURCE_DIR}/openocd.cfg)

add_custom_target(flash
    COMMAND openocd -f ${OPENOCD_CFG} -c "program $<TARGET_FILE:${TARGET}> verify reset exit"
    DEPENDS ${TARGET}
    USES_TERMINAL
)