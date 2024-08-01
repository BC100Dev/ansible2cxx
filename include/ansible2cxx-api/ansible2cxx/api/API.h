#ifndef ANSIBLE2CXX_API_H
#define ANSIBLE2CXX_API_H

#include <map>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;


using ModuleMap = std::map<std::string, std::string>;

struct ModuleOutput {
    int status;
    bool success;
    std::string message;
};

namespace Ansible2Cxx::API {

    namespace Builtin {

        namespace Modules {

            ModuleOutput AddHost(ModuleMap varMap);
            ModuleOutput Apt(ModuleMap varMap);
            ModuleOutput AptKey(ModuleMap varMap);
            ModuleOutput AptRepository(ModuleMap varMap);
            ModuleOutput Assemble(ModuleMap varMap);
            ModuleOutput Assert(ModuleMap varMap);
            ModuleOutput AsyncStatus(ModuleMap varMap);
            ModuleOutput BlockInFile(ModuleMap varMap);
            ModuleOutput Command(ModuleMap varMap);
            ModuleOutput CopyFile(ModuleMap varMap);
            ModuleOutput Cron(ModuleMap varMap);
            ModuleOutput Deb822_Repo(ModuleMap varMap);
            ModuleOutput DebConf(ModuleMap varMap);
            ModuleOutput Debug(ModuleMap varMap);
            ModuleOutput Dnf(ModuleMap varMap);
            ModuleOutput Dnf5(ModuleMap varMap);
            ModuleOutput DpkgSelections(ModuleMap varMap);
            ModuleOutput Fail(ModuleMap varMap);
            ModuleOutput Fetch(ModuleMap varMap);
            ModuleOutput File(ModuleMap varMap);
            ModuleOutput Find(ModuleMap varMap);
            ModuleOutput GatherFacts(ModuleMap varMap);
            ModuleOutput GetUrl(ModuleMap varMap);
            ModuleOutput GetEnt(ModuleMap varMap);
            ModuleOutput Git(ModuleMap varMap);
            ModuleOutput Group(ModuleMap varMap);
            ModuleOutput GroupBy(ModuleMap varMap);
            ModuleOutput Hostname(ModuleMap varMap);
            ModuleOutput ImportPlaybook(ModuleMap varMap);
            ModuleOutput ImportRole(ModuleMap varMap);
            ModuleOutput ImportTasks(ModuleMap varMap);
            ModuleOutput IncludeRole(ModuleMap varMap);
            ModuleOutput IncludeTasks(ModuleMap varMap);
            ModuleOutput IncludeVars(ModuleMap varMap);
            ModuleOutput IpTables(ModuleMap varMap);
            ModuleOutput KnownHosts(ModuleMap varMap);
            ModuleOutput LineInFile(ModuleMap varMap);
            ModuleOutput Meta(ModuleMap varMap);
            ModuleOutput Package(ModuleMap varMap);
            ModuleOutput PackageFacts(ModuleMap varMap);
            ModuleOutput Pause(ModuleMap varMap);
            ModuleOutput Ping(ModuleMap varMap);
            ModuleOutput Pip(ModuleMap varMap);
            ModuleOutput Raw(ModuleMap varMap);
            ModuleOutput Reboot(ModuleMap varMap);
            ModuleOutput Replace(ModuleMap varMap);
            ModuleOutput RpmKey(ModuleMap varMap);
            ModuleOutput Script(ModuleMap varMap);
            ModuleOutput Service(ModuleMap varMap);
            ModuleOutput ServiceFacts(ModuleMap varMap);
            ModuleOutput SetFact(ModuleMap varMap);
            ModuleOutput SetStats(ModuleMap varMap);
            ModuleOutput Setup(ModuleMap varMap);
            ModuleOutput Shell(ModuleMap varMap);
            ModuleOutput Slurp(ModuleMap varMap);
            ModuleOutput Stat(ModuleMap varMap);
            ModuleOutput Subversion(ModuleMap varMap);
            ModuleOutput SystemdService(ModuleMap varMap);
            ModuleOutput SysvInit(ModuleMap varMap);
            ModuleOutput Tempfile(ModuleMap varMap);
            ModuleOutput Template(ModuleMap varMap);
            ModuleOutput Unarchive(ModuleMap varMap);
            ModuleOutput URI(ModuleMap varMap);
            ModuleOutput User(ModuleMap varMap);
            ModuleOutput ValidateArgumentSpec(ModuleMap varMap);
            ModuleOutput WaitFor(ModuleMap varMap);
            ModuleOutput WaitForConnection(ModuleMap varMap);
            ModuleOutput YumRepo(ModuleMap varMap);

        }

        namespace BecomePlugins {
        }

        namespace ConnectionPlugins {
        }

        namespace InventoryPlugins {
        }

    }

    namespace NetCommon {
    }

    namespace Posix {
    }

    namespace Utils {
    }

}

namespace Ansible2Cxx::CommunityAPI {
}

#endif //ANSIBLE2CXX_API_H
