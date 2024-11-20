#include <ansible2cxx/App/CliArgs.hpp>
#include <ansible2cxx/Globals.hpp>
#include "ansible2cxx/Utils/Utils.hpp"

#include <filesystem>

namespace fs = std::filesystem;

using namespace Application::Utils;


std::string findCompilerByName(const std::string& name, bool cppCompiler) {
    std::vector<std::string> pathEnv = PathEnv();

    for (const std::string& pathItem : pathEnv) {
        if (fs::exists(pathItem) && fs::is_directory(pathItem)) {
            std::string _path = pathItem;
            _path.append("/").append(name).append(cppCompiler ? "g++" : "gcc");

            if (fs::exists(_path))
                return _path;
        }
    }

    return "";
}


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
    std::string compiler;

    if (arch == OUTPUT_ARCH_ARM64)
        compiler = findCompilerByName("x86_64-linux-gnu-", Application::CommandArgs::GCC_LANG == CPP);
    else if (arch == OUTPUT_ARCH_ARM64)
        compiler = findCompilerByName("aarch64-linux-gnu-", Application::CommandArgs::GCC_LANG == CPP);
    else if (arch == OUTPUT_ARCH_RISCV64)
        compiler = findCompilerByName("riscv64-linux-gnu-", Application::CommandArgs::GCC_LANG == CPP);
    else
        compiler = COMPILER_UNKNOWN;

    return compiler;
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