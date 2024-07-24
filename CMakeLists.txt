cmake_minimum_required(VERSION 3.20)
project(ansible2cxx)

set(CMAKE_CXX_STANDARD 17)

# available toolchains out of the box (see "toolchains" directory):
# Linux_amd64        = x86_64 / AMD64 / x64 Architectures
# Linux_arm64        = arm64 / aarch64 / arm-x64 Architectures (e.g. Raspberry Pi)
# Linux_MinGW_Win64  = Windows x64 compilers on Linux
if (DEFINED APP_CONFIG_TARGET AND APP_CONFIG_TARGET)
    if (EXISTS "${CMAKE_SOURCE_DIR}/toolchains/${APP_CONFIG_TARGET}.cmake")
        include("toolchains/${APP_CONFIG_TARGET}.cmake")
    else ()
        message(FATAL_ERROR "Toolchain file '${APP_CONFIG_TARGET}.cmake' does not exist")
    endif ()
endif ()

file(GLOB LOCAL_INCLUDE_DIRS "include/*")
include_directories(${LOCAL_INCLUDE_DIRS})

file (GLOB_RECURSE GLOBAL_SOURCES "src/**.cpp" "src/**/*.cpp")
add_executable(ansible2cxx "${GLOBAL_SOURCES}")