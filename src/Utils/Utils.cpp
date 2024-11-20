#include "ansible2cxx/Utils/Utils.hpp"
#include <sstream>
#include <ctime>
#include <string>
#include <iostream>
#include <stdexcept>

namespace Application::Utils {

#ifdef _WIN32
    std::string PATH_SEP_DELIM_STR = ";";
    char PATH_SEP_DELIM = ';';
#else
    std::string PATH_SEP_DELIM_STR = ":";
    char PATH_SEP_DELIM = ':';
#endif

    std::vector<std::string> Split(const std::string &str, const std::string &delim) {
        std::vector<std::string> items;
        size_t start = 0;
        size_t end = str.find(delim);

        while (end != std::string::npos) {
            items.push_back(str.substr(start, end - start));
            start = end + delim.length();
            end = str.find(delim, start);
        }

        items.push_back(str.substr(start));

        return items;
    }

    std::vector<std::string> PathEnv() {
        std::vector<std::string> items;

        const char *pathEnv = std::getenv("PATH");
        if (pathEnv == nullptr || std::string(pathEnv).empty())
            return items;

        std::string pathString(pathEnv);
        std::string delim;

#ifdef _WIN32
        delim = ";";
#else
        delim = ":";
#endif

        return Split(pathString, delim);
    }

    bool StringStartsWith(const std::string &str, const std::string &prefix) {
        return str.substr(0, prefix.size()) == prefix;
    }

    bool StringEndsWith(const std::string &str, const std::string &suffix) {
        if (suffix.size() > str.size()) return false;
        return str.substr(str.size() - suffix.size()) == suffix;
    }

    int GetRandomInteger(int min, int max) {
        std::srand(static_cast<int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

    long GetRandomLong(long min, long max) {
        std::srand(static_cast<int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

}