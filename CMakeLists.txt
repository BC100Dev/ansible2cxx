cmake_minimum_required(VERSION 3.20)
project(ansible2cxx VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# available toolchains out of the box (see "toolchains" directory):
# Linux_amd64        = x86_64 / AMD64 / x64 Architectures
# Linux_arm64        = arm64 / aarch64 / arm-x64 Architectures (e.g. Raspberry Pi)
# Linux_RISCV64      = RISC-V 64-bit on Linux systems
# Linux_MinGW_Win64  = Windows MinGW x64 compilers on Linux
if (DEFINED APP_CONFIG_TARGET AND APP_CONFIG_TARGET)
    if (EXISTS "${CMAKE_SOURCE_DIR}/toolchains/${APP_CONFIG_TARGET}.cmake")
        include("toolchains/${APP_CONFIG_TARGET}.cmake")
    else ()
        message(FATAL_ERROR "Toolchain file '${APP_CONFIG_TARGET}.cmake' does not exist.\nMake sure that the Toolchain file exists.")
    endif ()
else ()
    if (UNIX AND NOT APPLE AND "${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
        set(APP_SYSTEM_TARGET "Linux")
    elseif (WIN64)
        set(APP_SYSTEM_TARGET "Win64")
    else()
        message(FATAL_ERROR "Unsupported OS; macOS systems aren't supported yet.")
    endif ()

    if (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "amd64")
        set(APP_SYSTEM_ARCH "x86_64")
    elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
        set(APP_SYSTEM_ARCH "aarch64")
    elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "riscv64")
        set(APP_SYSTEM_ARCH "riscv64")
    else ()
        message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
    endif ()
endif ()

add_subdirectory(external/yaml-cpp)

file(GLOB LOCAL_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include/*")
include_directories(${LOCAL_INCLUDE_DIRS})
include_directories(external/yaml-cpp/include)

file(GLOB_RECURSE UTIL_SOURCES "${CMAKE_SOURCE_DIR}/src/Utils/**.cpp" "${CMAKE_SOURCE_DIR}/src/Utils/**/*.cpp")
file(GLOB_RECURSE APP_SOURCES "${CMAKE_SOURCE_DIR}/src/Application/**.cpp" "${CMAKE_SOURCE_DIR}/src/Application/**/*.cpp")

add_library(ansible2cxx-utils STATIC "${UTIL_SOURCES}")

file(GLOB_RECURSE Ansible2Cxx_API_SOURCES "${CMAKE_SOURCE_DIR}/src/API/**.cpp")
add_library(ansible2cxx-api STATIC "${Ansible2Cxx_API_SOURCES}")
target_link_libraries(ansible2cxx-api PRIVATE ansible2cxx-utils)

add_executable(ansible2cxx "${APP_SOURCES}")
target_link_libraries(ansible2cxx PRIVATE ansible2cxx-utils yaml-cpp)

if (${APP_SYSTEM_ARCH} STREQUAL "x86_64")
    if (${APP_SYSTEM_TARGET} STREQUAL "Linux")
        find_package(Qt6 REQUIRED COMPONENTS Widgets Core)
        include_directories(${Qt6Widgets_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS})
    endif ()

    file(GLOB_RECURSE APP_GUI_WIN64_SOURCES "${CMAKE_SOURCE_DIR}/src/ApplicationGUI/Win64/**.cpp" "${CMAKE_SOURCE_DIR}/src/ApplicationGUI/Win64/**/*.cpp")
    file(GLOB_RECURSE APP_GUI_LINUX_SOURCES "${CMAKE_SOURCE_DIR}/src/ApplicationGUI/Qt/**.cpp" "${CMAKE_SOURCE_DIR}/src/ApplicationGUI/Qt/**/*.cpp")
    file(GLOB APP_GUI_GLOB_SOURCES "${CMAKE_SOURCE_DIR}/src/ApplicationGUI/**.cpp" "${CMAKE_SOURCE_DIR}/src/ApplicationGUI/**.h")

    set(APP_GUI_SOURCES ${APP_GUI_GLOB_SOURCES})

    if ("${APP_SYSTEM_TARGET}" STREQUAL "Linux")
        list(APPEND APP_GUI_SOURCES ${APP_GUI_LINUX_SOURCES})
    elseif ("${APP_SYSTEM_TARGET}" STREQUAL "Win64")
        list(APPEND APP_GUI_SOURCES ${APP_GUI_WIN64_SOURCES})
    endif ()

    add_executable(ansible2cxx-gui "${APP_GUI_SOURCES}")
    target_link_libraries(ansible2cxx-gui PRIVATE ansible2cxx-utils yaml-cpp)

    if (${APP_SYSTEM_TARGET} STREQUAL "Linux")
        target_link_libraries(ansible2cxx-gui PRIVATE Qt6::Widgets Qt6::Core)
    endif ()
endif ()

if (EXISTS "${CMAKE_SOURCE_DIR}/src/TestCode.cpp")
    message("$ Found TestCode.cpp")
    add_executable(ansible2cxx-test "src/TestCode.cpp")
    target_link_libraries(ansible2cxx-test PRIVATE ansible2cxx-utils yaml-cpp)
endif ()