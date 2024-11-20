#include <ansible2cxx/api/API.hpp>

#include <sstream>
#include <algorithm>

#ifdef _WIN32
#include <ansible2cxx/api/Win32_API.hpp>
#endif

#ifdef __linux__
#include <ansible2cxx/api/Posix_API.hpp>
#endif

namespace Ansible2Cxx::API {

    namespace Builtin::Modules {

        ModuleOutput CopyFile(const ModuleInputData& listMap) {
            ModuleOutput output;

            return output;
        }

        ModuleOutput FileCmd(const ModuleInputData& listMap) {
            return ModuleOutput{};
        }

    }

}