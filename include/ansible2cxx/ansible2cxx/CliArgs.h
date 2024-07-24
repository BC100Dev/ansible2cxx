#ifndef ANSIBLE2CXX_CLIARGS_H
#define ANSIBLE2CXX_CLIARGS_H

#include <string>

namespace Application::CommandArgs {

    extern bool NO_COMPILE;
    extern bool EXEC_BUILD;

    extern std::string ANSIBLE_IN_DIRECTORY;
    extern std::string BUILD_OUT_DIRECTORY;

}

#endif //ANSIBLE2CXX_CLIARGS_H
