#!/bin/bash

# shellcheck disable=SC2162

read -p "Name for the Toolchain: " TOOLCHAIN_NAME
read -p "Path to GCC/Clang (C Compiler): " GCC_PATH
read -p "Path to G++/Clang++ (C++ Compiler): " GPP_PATH

ABS_PATH_GCC=$(command -v "$GCC_PATH")
ABS_PATH_GPP=$(command -v "$GPP_PATH")

set -e

if [ -z "$GCC_PATH" ] || [ -z "$GPP_PATH" ]; then
  echo "Input paths cannot be empty."
  exit 1
fi

if ! [ -f "$ABS_PATH_GCC" ] || ! [ -x "$ABS_PATH_GCC" ]; then
  echo "GCC/Clang command not found."
  exit 1
fi

if ! [ -f "$ABS_PATH_GPP" ] || ! [ -x "$ABS_PATH_GPP" ]; then
  echo "G++/Clang++ command not found."
  exit 1
fi


FILE_OUT="toolchains/${TOOLCHAIN_NAME}.cmake"

echo "message(\"__ Using Toolchain '$TOOLCHAIN_NAME' __\")

message(\"-- Setting C compiler to $ABS_PATH_GCC\")
set(CMAKE_C_COMPILER \"$ABS_PATH_GCC\")

message(\"-- Setting C++ compiler to $ABS_PATH_GPP\")
set(CMAKE_CXX_COMPILER \"$ABS_PATH_GPP\")

set(APP_SYSTEM_TARGET \"Linux\")" > "$FILE_OUT"

if [ -f "$FILE_OUT" ]; then
    echo "Toolchain file created successfully."
else
    echo "Failed to create toolchain file."
    exit 1
fi

set +e