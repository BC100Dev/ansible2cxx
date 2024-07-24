#include <ansible2cxx/CliArgs.h>

namespace Application::CommandArgs {

    bool NO_COMPILE = false;
    bool EXEC_BUILD = false;

    std::string ANSIBLE_IN_DIRECTORY = ".";
    std::string BUILD_OUT_DIRECTORY = "ansible-cxx-out";

}