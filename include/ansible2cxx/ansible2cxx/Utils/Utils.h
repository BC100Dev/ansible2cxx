#ifndef ANSIBLE2CXX_UTILS_H
#define ANSIBLE2CXX_UTILS_H

#include <string>
#include <vector>

namespace Application::Utils {

    std::vector<std::string> PathEnv();

    bool StringStartsWith(const std::string& str, const std::string& prefix);

}

#endif //ANSIBLE2CXX_UTILS_H
