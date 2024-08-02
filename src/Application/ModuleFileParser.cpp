#include <ansible2cxx/App/ModuleFileParser.h>

namespace Ansible2Cxx {

    std::vector<ModuleInput> LoadModules(const std::string& filePath, bool loadExternalFiles) {
        std::vector<ModuleInput> input;
        return input;
    }

    std::vector<ModuleInput> LoadModules(const std::string& filePath) {
        return LoadModules(filePath, true);
    }

}