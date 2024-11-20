#ifndef ANSIBLE2CXX_PKGAPI_H
#define ANSIBLE2CXX_PKGAPI_H

#include <stdbool.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PKG_EXEC_DEFAULT_CODE_SUCCESS 0x00000000;
#define PKG_EXEC_DEFAULT_CODE_ERROR 0x00000001;
#define PKG_EXEC_DEFAULT_CODE_FATAL 0x8020ffff;
#define PKG_EXEC_DEFAULT_CODE_WARN 0x1ba3ee00;
#define PKG_EXEC_DEFAULT_CODE_SKIP 0x9caa1a3d;
#define PKG_EXEC_DEFAULT_CODE_APPLIED 0x0000c3d3;

typedef struct {
    const char *key;
    const char *value;
    bool required;
} ModuleMap;

typedef struct {
    ModuleMap *items;
    size_t capacity;
} ModuleInputData;

typedef struct {
    long outputCode;
    const char *message;
    const char *errString;
    const char *outString;
} ModuleOutput;

typedef struct {
    const char *sharedLibraryPath;
    const char *ansibleNamespace;
    const char *ansibleLabel;
    const char *cxxMethodName;
} ModuleCaller;

ModuleOutput CallModule(const ModuleCaller &caller, const ModuleInputData &inputData);

void FreeLibraries();

#ifdef __cplusplus
};
#endif

#endif //ANSIBLE2CXX_PKGAPI_H
