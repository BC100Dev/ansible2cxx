#ifndef ANSIBLE2CXX_GLOBALS_H
#define ANSIBLE2CXX_GLOBALS_H

#if defined(__riscv) && (__riscv_xlen == 64)
#define SYSTEM_RISCV64
#endif

#if defined(__x86_64__) || defined(_M_X64)
#define SYSTEM_AMD64
#endif

#if defined(__aarch64__) || defined(__arm__) || defined(_M_ARM)
#define SYSTEM_ARM64
#endif

#endif //ANSIBLE2CXX_GLOBALS_H
