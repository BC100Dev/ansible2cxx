#ifndef ANSIBLE2CXX_API_HPP
#define ANSIBLE2CXX_API_HPP

#include <ansible2cxx/pkg_api/PkgAPI.h>

namespace Ansible2Cxx::API {

    namespace Builtin {

        namespace Modules {

            ModuleOutput AddHost(const ModuleInputData& listMap);

            ModuleOutput Apt(const ModuleInputData& listMap);

            ModuleOutput AptKey(const ModuleInputData& listMap);

            ModuleOutput AptRepository(const ModuleInputData& listMap);

            ModuleOutput Assemble(const ModuleInputData& listMap);

            ModuleOutput Assert(const ModuleInputData& listMap);

            ModuleOutput AsyncStatus(const ModuleInputData& listMap);

            ModuleOutput BlockInFile(const ModuleInputData& listMap);

            ModuleOutput Command(const ModuleInputData& listMap);

            ModuleOutput CopyFile(const ModuleInputData& listMap);

            ModuleOutput Cron(const ModuleInputData& listMap);

            ModuleOutput Deb822_Repo(const ModuleInputData& listMap);

            ModuleOutput DebConf(const ModuleInputData& listMap);

            ModuleOutput Debug(const ModuleInputData& listMap);

            ModuleOutput Dnf(const ModuleInputData& listMap);

            ModuleOutput Dnf5(const ModuleInputData& listMap);

            ModuleOutput DpkgSelections(const ModuleInputData& listMap);

            ModuleOutput Fail(const ModuleInputData& listMap);

            ModuleOutput Fetch(const ModuleInputData& listMap);

            ModuleOutput FileCmd(const ModuleInputData& listMap);

            ModuleOutput Find(const ModuleInputData& listMap);

            ModuleOutput GatherFacts(const ModuleInputData& listMap);

            ModuleOutput GetUrl(const ModuleInputData& listMap);

            ModuleOutput GetEnt(const ModuleInputData& listMap);

            ModuleOutput Git(const ModuleInputData& listMap);

            ModuleOutput Group(const ModuleInputData& listMap);

            ModuleOutput GroupBy(const ModuleInputData& listMap);

            ModuleOutput Hostname(const ModuleInputData& listMap);

            ModuleOutput ImportPlaybook(const ModuleInputData& listMap);

            ModuleOutput ImportRole(const ModuleInputData& listMap);

            ModuleOutput ImportTasks(const ModuleInputData& listMap);

            ModuleOutput IncludeRole(const ModuleInputData& listMap);

            ModuleOutput IncludeTasks(const ModuleInputData& listMap);

            ModuleOutput IncludeVars(const ModuleInputData& listMap);

            ModuleOutput IpTables(const ModuleInputData& listMap);

            ModuleOutput KnownHosts(const ModuleInputData& listMap);

            ModuleOutput LineInFile(const ModuleInputData& listMap);

            ModuleOutput Meta(const ModuleInputData& listMap);

            ModuleOutput Package(const ModuleInputData& listMap);

            ModuleOutput PackageFacts(const ModuleInputData& listMap);

            ModuleOutput Pause(const ModuleInputData& listMap);

            ModuleOutput Ping(const ModuleInputData& listMap);

            ModuleOutput Pip(const ModuleInputData& listMap);

            ModuleOutput Raw(const ModuleInputData& listMap);

            ModuleOutput Reboot(const ModuleInputData& listMap);

            ModuleOutput Replace(const ModuleInputData& listMap);

            ModuleOutput RpmKey(const ModuleInputData& listMap);

            ModuleOutput Script(const ModuleInputData& listMap);

            ModuleOutput Service(const ModuleInputData& listMap);

            ModuleOutput ServiceFacts(const ModuleInputData& listMap);

            ModuleOutput SetFact(const ModuleInputData& listMap);

            ModuleOutput SetStats(const ModuleInputData& listMap);

            ModuleOutput Setup(const ModuleInputData& listMap);

            ModuleOutput Shell(const ModuleInputData& listMap);

            ModuleOutput Slurp(const ModuleInputData& listMap);

            ModuleOutput Stat(const ModuleInputData& listMap);

            ModuleOutput Subversion(const ModuleInputData& listMap);

            ModuleOutput SystemdService(const ModuleInputData& listMap);

            ModuleOutput SysvInit(const ModuleInputData& listMap);

            ModuleOutput Tempfile(const ModuleInputData& listMap);

            ModuleOutput Template(const ModuleInputData& listMap);

            ModuleOutput Unarchive(const ModuleInputData& listMap);

            ModuleOutput URI(const ModuleInputData& listMap);

            ModuleOutput User(const ModuleInputData& listMap);

            ModuleOutput ValidateArgumentSpec(const ModuleInputData& listMap);

            ModuleOutput WaitFor(const ModuleInputData& listMap);

            ModuleOutput WaitForConnection(const ModuleInputData& listMap);

            ModuleOutput YumRepo(const ModuleInputData& listMap);

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

    namespace Utils {
    }

}

namespace Ansible2Cxx::CommunityAPI {
}

#endif //ANSIBLE2CXX_API_HPP
