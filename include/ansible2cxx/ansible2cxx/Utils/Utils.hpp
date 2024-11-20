#ifndef ANSIBLE2CXX_UTILS_HPP
#define ANSIBLE2CXX_UTILS_HPP

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <stdexcept>

class ApplicationError : public std::runtime_error {
public:
    explicit ApplicationError(const std::string& message)
            : std::runtime_error(message) {}

    ApplicationError(const std::string& message, int code)
            : std::runtime_error(message), errorCode(code) {}

    int getCode() const noexcept {
        return errorCode;
    }

    const char* what() const noexcept override {
        fullMessage = std::runtime_error::what();

        if (errorCode != 0)
            fullMessage += " (Error Code: " + std::to_string(errorCode) + ")";

        return fullMessage.c_str();
    }

private:
    int errorCode = 0;
    mutable std::string fullMessage;
};

namespace Application::Utils {

    extern std::string PATH_SEP_DELIM_STR;
    extern char PATH_SEP_DELIM;

    std::vector<std::string> Split(const std::string &str, const std::string &delim);

    std::vector<std::string> PathEnv();

    bool StringStartsWith(const std::string &str, const std::string &prefix);

    bool StringEndsWith(const std::string &str, const std::string &suffix);

    int GetRandomInteger(int min, int max);

    long GetRandomLong(long min, long max);

}

#endif //ANSIBLE2CXX_UTILS_HPP
