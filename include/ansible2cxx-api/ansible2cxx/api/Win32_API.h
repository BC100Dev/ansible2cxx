#ifndef ANSIBLE2CXX_WIN32_API_H
#define ANSIBLE2CXX_WIN32_API_H

#include <ansible2cxx/api/API.h>

namespace Ansible2Cxx::API::Win32 {

    namespace Modules {
        ModuleOutput AsyncStatus(ModuleMap varMap);
        ModuleOutput Setup(ModuleMap varMap);
        ModuleOutput Slurp(ModuleMap varMap);
        ModuleOutput WinAcl(ModuleMap varMap);
        ModuleOutput WinAclInheritance(ModuleMap varMap);
        ModuleOutput WinCertSTore(ModuleMap varMap);
        ModuleOutput WinCommand(ModuleMap varMap);
        ModuleOutput WinCopy(ModuleMap varMap);
        ModuleOutput WinDnsClient(ModuleMap varMap);
        ModuleOutput WinDomain(ModuleMap varMap);
        ModuleOutput WinDomainController(ModuleMap varMap);
        ModuleOutput WinDomainMembership(ModuleMap varMap);
        ModuleOutput WinDsc(ModuleMap varMap);
        ModuleOutput WinEnv(ModuleMap varMap);
        ModuleOutput WinFeature(ModuleMap varMap);
        ModuleOutput WinFile(ModuleMap varMap);
        ModuleOutput WinFind(ModuleMap varMap);
        ModuleOutput Win_GetURl(ModuleMap varMap);
        ModuleOutput WinGroup(ModuleMap varMap);
        ModuleOutput WinGroupMembership(ModuleMap varMap);
        ModuleOutput WinHostname(ModuleMap varMap);
        ModuleOutput WinOptionalFeature(ModuleMap varMap);
        ModuleOutput WinOwner(ModuleMap varMap);
        ModuleOutput WinPackage(ModuleMap varMap);
        ModuleOutput WinPath(ModuleMap varMap);
        ModuleOutput WinPing(ModuleMap varMap);
        ModuleOutput WinPowershell(ModuleMap varMap);
        ModuleOutput WinReboot(ModuleMap varMap);
        ModuleOutput WinRegStat(ModuleMap varMap);
        ModuleOutput WinRegedit(ModuleMap varMap);
        ModuleOutput WinService(ModuleMap varMap);
        ModuleOutput WinServiceInfo(ModuleMap varMap);
        ModuleOutput WinShare(ModuleMap varMap);
        ModuleOutput WinShell(ModuleMap varMap);
        ModuleOutput WinStat(ModuleMap varMap);
        ModuleOutput WinTempfile(ModuleMap varMap);
        ModuleOutput WinTemplate(ModuleMap varMap);
        ModuleOutput WinUpdates(ModuleMap varMap);
        ModuleOutput WinUri(ModuleMap varMap);
        ModuleOutput WinUser(ModuleMap varMap);
        ModuleOutput WinUserRight(ModuleMap varMap);
        ModuleOutput WinWaitFor(ModuleMap varMap);
        ModuleOutput Win_WhoAmI(ModuleMap varMap);
    }

    namespace FilterPlugins {
    }

}

#endif //ANSIBLE2CXX_WIN32_API_H
