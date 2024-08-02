#ifndef ANSIBLE2CXX_UTILS_H
#define ANSIBLE2CXX_UTILS_H

#include <string>
#include <vector>

namespace Application::Utils {

    std::vector<std::string> PathEnv();

    bool StringStartsWith(const std::string& str, const std::string& prefix);

    std::string ReadFile(const std::string& filePath);

    int GetRandomInteger(int min, int max);

    long GetRandomLong(int min, int max);

}

#endif //ANSIBLE2CXX_UTILS_H
