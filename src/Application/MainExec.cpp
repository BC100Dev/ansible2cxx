#include <iostream>

#include <ansible2cxx/App/CliArgs.h>
#include <ansible2cxx/Utils/HelpPage.h>

using namespace Application::CommandArgs;


void displayHelp() {
    std::cout << "ansible2cxx (Ansible to C/C++)" << std::endl;
    std::cout << "v1.0" << std::endl << std::endl << "usage: ansible2cxx [options] [input] [output]" << std::endl;
    std::cout << "options:" << std::endl;

    HelpPage page;
    page.setSpaceWidth(4);
    page.addArg("-ne  | --no-exec", "", "Do not execute the application upon compilation");
    page.addArg("-r   | --run-only", "",
                "Run the Ansible script on C/C++ level without compiling (interpret the script)");
    page.addArg("-lsh | --library-shared", "", "Build the C/C++ as a shared library instead of an executable");
    page.addArg("-lst | --library-static", "", "Build the C/C++ as a static library instead of an executable");
    page.addArg("--source-dir", "[SRC_DIR]", "Puts the source code for manual compilation with CMake");
    page.addArg("--gcc-flags", "[FLAGS]", "Add additional flags to the C/C++ compiler");
    page.addArg("--gcc-version", "[VER]", "Specify the C/C++ version (default: C++17,C11)");
    page.addArg("--gcc-lang", "[LANG]", "Puts the source code in either C or C++ (default: C++)");
    page.display(std::cout);
    page.free();

    std::cout << std::endl;

    std::cout << "The input file is the Ansible script, which takes in the main Ansible script that you usually run."
              << std::endl;
    std::cout
            << "That script can include custom roles and specific actions, and its Interpreter will write the C/C++ code for you."
            << std::endl << std::endl;

    std::cout
            << "The output file is eventually the executable binary that you can use to execute. If used as a library,"
            << std::endl;
    std::cout << "It can be used to be loaded from other executables." << std::endl;
}

void parseArgs(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        // Code Inspiration: https://github.com/BeChris100/aboawt
        std::string arg = argv[i];

        if (arg[0] == '-') {
            if (arg == "-ne" || arg == "--no-exec")
                EXEC_BUILD = false;

            if (arg == "-r" || arg == "--run-only")
                INTERPRETER_ONLY = true;
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        displayHelp();
        return 1;
    }

    parseArgs(argc, argv);

    return 0;
}
