#include <ansible2cxx/pkg_api/PkgAPI.h>
#include <ansible2cxx/pkg_api/PkgAPI.hpp>

#include <iostream>
#include <optional>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>

#ifdef __linux__

#include <dlfcn.h>

#endif

using namespace Ansible2Cxx::PkgAPI;

namespace Ansible2Cxx::PkgAPI {

    std::vector<ModuleMap> InDataToVec(const ModuleInputData &inData) {
        std::vector<ModuleMap> outData;

        for (int i = 0; i < inData.capacity; i++) {
            ModuleMap it = inData.items[i];
            outData.push_back(it);
        }

        return outData;
    }

    ModuleInputData VecToInData(const std::vector<ModuleMap> &vecData) {
        ModuleInputData inData;

        unsigned long capacity = vecData.size();
        inData.capacity = vecData.size();

        inData.items = (ModuleMap *) malloc(capacity * sizeof(ModuleMap));

        for (unsigned long i = 0; i < vecData.size(); i++) {
            ModuleMap it = vecData[i];
            inData.items[i] = it;
        }

        return inData;
    }

}


void *openHandle(const std::string &libFilePath) {
    void *handle;

#ifdef __linux__
    handle = dlopen(libFilePath.c_str(), RTLD_NOW);
#endif

    return handle;
}

ModuleOutput CallModule(const ModuleCaller &caller, const ModuleInputData &inputData) {
    ModuleOutput output = {0};

    if (!caller.sharedLibraryPath || !caller.cxxMethodName) {
        output.outputCode = PKG_EXEC_DEFAULT_CODE_FATAL;
        output.errString = "Invalid ModuleCaller: Missing library path and/or CXX method name";
        return output;
    }

    // linux only support for now
#ifdef __linux__
    void *libHandle = nullptr;
    for (const auto &it: IndexedLibraries) {
        if (it.libFilePath == caller.sharedLibraryPath) {
            libHandle = it.libHandle;
            break;
        }
    }

    if (!libHandle) {
        libHandle = openHandle(caller.sharedLibraryPath);
        if (!libHandle) {
            std::stringstream ss;
            ss << "Failed to open shared library at \"" << caller.sharedLibraryPath << "\""
               << " Error: " << dlerror();

            std::string errString = ss.str();

            output.outputCode = PKG_EXEC_DEFAULT_CODE_FATAL;
            output.errString = strdup(errString.c_str());
            return output;
        }

        IndexedLibrary it;
        it.libHandle = libHandle;
        it.libFilePath = caller.sharedLibraryPath;

        IndexedLibraries.push_back(it);
    }

    auto *cxxMethod = (ModuleOutput (*)(const ModuleInputData &)) dlsym(libHandle, caller.cxxMethodName);
    if (!cxxMethod) {
        std::stringstream ss;
        ss << "Failed to find method \"" << caller.cxxMethodName << "\" in shared library at \""
           << caller.sharedLibraryPath << "\""
           << " Error: " << dlerror();

        std::string errString = ss.str();

        output.outputCode = PKG_EXEC_DEFAULT_CODE_FATAL;
        output.errString = errString.c_str();
        return output;
    }

    try {
        output = cxxMethod(inputData);

        for (int i = 0; i < inputData.capacity; i++) {
            free((void*)inputData.items[i].key);
            free((void*)inputData.items[i].value);
        }

        free(inputData.items);

        return output;
    } catch (const std::exception &e) {
        output.outputCode = PKG_EXEC_DEFAULT_CODE_FATAL;
        output.errString = e.what();
    } catch (...) {
        output.outputCode = PKG_EXEC_DEFAULT_CODE_FATAL;
        output.errString = "Unknown exception";
    }
#endif

    return output;
}

void FreeLibraries() {
    for (auto it : IndexedLibraries) {
        if (it.libHandle) {
#ifdef __linux__
            dlclose(it.libHandle);
#endif

            it.libHandle = nullptr;
        }
    }

    IndexedLibraries.clear();
    IndexedLibraries.shrink_to_fit();
}