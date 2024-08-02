#ifndef ANSIBLE2CXX_MODULEFILEPARSER_H
#define ANSIBLE2CXX_MODULEFILEPARSER_H

#include <string>
#include <vector>

namespace Ansible2Cxx {

    struct ModuleInput {
        std::string libName;
        std::string modName;
        std::string funcName;
    };

    std::vector<ModuleInput> LoadModules(const std::string& filePath, bool loadExternalFiles);
    std::vector<ModuleInput> LoadModules(const std::string& filePath);

}


#endif //ANSIBLE2CXX_MODULEFILEPARSER_H
