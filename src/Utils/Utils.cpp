#include <ansible2cxx/Utils/Utils.h>
#include <sstream>
#include <ctime>

namespace Application::Utils {

    std::vector<std::string> PathEnv() {
        std::vector<std::string> items;

        const char *pathEnv = std::getenv("PATH");
        if (pathEnv == nullptr || std::string(pathEnv).empty())
            return items;

        std::string pathString(pathEnv);
        char delim;

#ifdef _WIN32
        delim = ';';
#else
        delim = ':';
#endif

        if (pathString.find(delim) == std::string::npos) {
            items.push_back(pathString);
            return items;
        }

        std::stringstream ss(pathString);
        std::string _path;

        while (std::getline(ss, _path, delim)) {
            if (!_path.empty())
                items.push_back(_path);
        }

        return items;
    }

    bool StringStartsWith(const std::string &str, const std::string &prefix) {
        return str.substr(0, prefix.size()) == prefix;
    }

    std::string ReadFile(const std::string& filePath) {
        return "";
    }

    int GetRandomInteger(int min, int max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

    long GetRandomLong(long min, long max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

}