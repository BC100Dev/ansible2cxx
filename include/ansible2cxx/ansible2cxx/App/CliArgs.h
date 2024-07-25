#ifndef ANSIBLE2CXX_CLIARGS_H
#define ANSIBLE2CXX_CLIARGS_H

#include <string>

#define FIGURE_OUT "{{ __figures__ }}"

#define OUTPUT_TYPE_LIBRARY_SHARED "shared"
#define OUTPUT_TYPE_LIBRARY_STATIC "static"
#define OUTPUT_TYPE_EXECUTABLE "executable"

#define OUTPUT_ARCH_ARM64 "arch:arm64"
#define OUTPUT_ARCH_AMD64 "arch:x86_64"
#define OUTPUT_ARCH_RISCV64 "arch:riscv64"
#define OUTPUT_ARCH_UNKNOWN "arch:?"

enum GccLanguage {

    C,

    CPP

};

namespace Application::CommandArgs {

    extern bool INTERPRETER_ONLY;
    extern bool EXEC_BUILD;
    extern std::string OUTPUT_TYPE;
    extern std::string OUTPUT_ARCH;
    extern bool CMAKE_SOURCES;

    extern std::string ANSIBLE_IN_FILE;
    extern std::string BUILD_OUT_DIRECTORY;
    extern std::string OUTPUT_FILENAME;

    extern int GCC_VER_C;
    extern int GCC_VER_CXX;

    extern GccLanguage GCC_LANG;
    extern std::string GCC_FLAGS_EXTRA;

}

#endif //ANSIBLE2CXX_CLIARGS_H
