#ifndef ANSIBLE2CXX_VARHANDLE_HPP
#define ANSIBLE2CXX_VARHANDLE_HPP

#include <ansible2cxx/pkg_api/PkgAPI.h>

#include <map>
#include <string>
#include <vector>

namespace Ansible {

    extern std::map<std::string, std::string> variables;
    extern std::vector<ModuleCaller> tasks;

}

#endif //ANSIBLE2CXX_VARHANDLE_HPP
