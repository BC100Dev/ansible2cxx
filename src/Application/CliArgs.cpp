#include <ansible2cxx/App/CliArgs.h>
#include <ansible2cxx/Globals.h>


std::string GetRunningArchitecture() {
    std::string str = OUTPUT_ARCH_UNKNOWN;

#ifdef SYSTEM_AMD64
    str = OUTPUT_ARCH_AMD64;
#endif

#ifdef SYSTEM_ARM64
    str = OUTPUT_ARCH_ARM64;
#endif

#ifdef SYSTEM_RISCV64
    str = OUTPUT_ARCH_RISCV64;
#endif

    return str;
}

std::string GetDefaultCompiler() {
    std::string arch = GetRunningArchitecture();
    //if (arch == OUTPUT_ARCH_ARM64)
    return "";
}

namespace Application::CommandArgs {

    bool INTERPRETER_ONLY = false;
    bool EXEC_BUILD = true;
    std::string OUTPUT_TYPE = OUTPUT_TYPE_EXECUTABLE;
    std::string OUTPUT_ARCH = GetRunningArchitecture();
    std::string COMPILER = GetDefaultCompiler();
    bool CMAKE_SOURCES = true;

    std::string ANSIBLE_IN_FILE = "script.yml";
    std::string BUILD_OUT_DIRECTORY = "ansible-cxx-out";
    std::string OUTPUT_FILENAME = FIGURE_OUT;

    int GCC_VER_C = 11;
    int GCC_VER_CXX = 17;

    GccLanguage GCC_LANG = CPP;
    std::string GCC_FLAGS_EXTRA;


}