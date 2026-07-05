set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# Don't try to link an executable when CMake tests the compiler.
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Compiler flags
set(CMAKE_C_FLAGS
    "-mcpu=cortex-m3 -mthumb -ffreestanding -fdata-sections -ffunction-sections -Wall"
)

set(CMAKE_CXX_FLAGS
    "-mcpu=cortex-m3 -mthumb -ffreestanding -fdata-sections -ffunction-sections -Wall -fno-exceptions -fno-rtti"
)

set(CMAKE_ASM_FLAGS
    "-mcpu=cortex-m3 -mthumb"
)

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS
    "-mcpu=cortex-m3 -mthumb -Wl,--gc-sections"
)