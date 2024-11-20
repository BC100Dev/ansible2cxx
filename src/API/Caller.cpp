#include <ansible2cxx/api/Caller.hpp>

#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <climits>

std::string getExecutablePath() {
#ifdef __linux__
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);

    if (count != 1)
        return {result, static_cast<size_t>(count)};

#endif

    return ERR_EXEC_LINK_FAIL;
}

namespace Ansible2Cxx {

    bool HavePermission(PermissionLevel level) {
#ifdef __linux__
        std::string filepath = getExecutablePath();
        if (filepath == ERR_EXEC_LINK_FAIL)
            return false;

        struct stat fileStat{};
        if (stat(filepath.c_str(), &fileStat) != 0) {
            std::cerr << "[Error] File Status Error: " << filepath << std::endl;
            return false;
        }

        switch (level) {
            case SetUID:
                return (fileStat.st_mode & S_ISUID) != 0;
            case SetGID:
                return (fileStat.st_mode & S_ISGID) != 0;
            case Executable:
                return (fileStat.st_mode & S_IXUSR) != 0;
            case Writable:
                return (fileStat.st_mode & S_IWUSR) != 0;
            case Readable:
                return (fileStat.st_mode & S_IRUSR) != 0;
            default:
                return false;
        }
#else
        return false;
#endif
    }

}