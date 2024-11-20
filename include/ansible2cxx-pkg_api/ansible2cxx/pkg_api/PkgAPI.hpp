#ifndef ANSIBLE2CXX_PKGAPI_HPP
#define ANSIBLE2CXX_PKGAPI_HPP

#include <ansible2cxx/pkg_api/PkgAPI.h>

#include <string>
#include <vector>

namespace Ansible2Cxx::PkgAPI {

    struct IndexedLibrary {
        std::string libFilePath;
        void *libHandle{};
    };

    std::vector<ModuleMap> InDataToVec(const ModuleInputData &inData);

    ModuleInputData VecToInData(const std::vector<ModuleMap> &vecData);

    extern std::vector<IndexedLibrary> IndexedLibraries;

}

#endif //ANSIBLE2CXX_PKGAPI_HPP
