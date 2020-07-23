# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

set(CMAKE_SYSTEM_PROCESSOR cortex-m7)

if(MBED_TOOLCHAIN STREQUAL "GCC_ARM")

set(GCC_FLAGS " \
    -mthumb \
    -mcpu=cortex-m7 \
")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    ${GCC_FLAGS} \
")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    ${GCC_FLAGS} \
")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} \
    ${GCC_FLAGS} \
")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} \
    ${GCC_FLAGS} \
")

elseif(MBED_TOOLCHAIN STREQUAL "ARM")

set(ARM_FLAGS " \
    -mcpu=cortex-m7 \
    -mfpu=none \
")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
    ${ARM_FLAGS} \
")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    ${ARM_FLAGS} \
")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} \
    --cpu=Cortex-M7.no_fp \
")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} \
    --cpu=Cortex-M7.no_fp \
")

endif()

add_definitions(
    -D__CORTEX_M7
    -DARM_MATH_CM7
    -D__CMSIS_RTOS
    -D__MBED_CMSIS_RTOS_CM
)
