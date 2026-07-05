cmake_minimum_required(VERSION 3.22)

project(BluePill LANGUAGES C CXX ASM)

set(TARGET bluepill_fw)

add_executable(${TARGET})

set_target_properties(${TARGET} PROPERTIES SUFFIX ".elf")

# main app
add_subdirectory(app/main)

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
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND arm-none-eabi-size $<TARGET_FILE:${TARGET}>
    COMMAND arm-none-eabi-objcopy -O ihex   $<TARGET_FILE:${TARGET}> ${CMAKE_BINARY_DIR}/${TARGET}.hex
    COMMAND arm-none-eabi-objcopy -O binary $<TARGET_FILE:${TARGET}> ${CMAKE_BINARY_DIR}/${TARGET}.bin
)

# dump
add_custom_target(dump
    COMMAND arm-none-eabi-objdump -D -S $<TARGET_FILE:${TARGET}> > ${CMAKE_BINARY_DIR}/${TARGET}.lst
    COMMAND arm-none-eabi-readelf -a $<TARGET_FILE:${TARGET}> > ${CMAKE_BINARY_DIR}/${TARGET}.elf.txt
    DEPENDS ${TARGET}
    USES_TERMINAL
)

# flash
set(OPENOCD_CFG ${CMAKE_SOURCE_DIR}/openocd.cfg)

add_custom_target(flash
    COMMAND openocd -f ${OPENOCD_CFG} -c "program $<TARGET_FILE:${TARGET}> verify reset exit"
    DEPENDS ${TARGET}
    USES_TERMINAL
)