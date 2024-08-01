#ifndef ANSIBLE2CXX_VARHANDLE_H
#define ANSIBLE2CXX_VARHANDLE_H

#include <ansible2cxx/App/TaskHandler.h>

#include <map>
#include <string>

namespace Ansible {

    extern std::map<std::string, std::string> variables;
    extern std::map<std::string, Ansible::Task> tasks;

}

#endif //ANSIBLE2CXX_VARHANDLE_H
