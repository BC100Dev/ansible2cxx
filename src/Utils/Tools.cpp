#include <ansible2cxx/Utils/Tools.hpp>
#include <ansible2cxx/Utils/Utils.hpp>

std::vector<std::string> translateCmdLine(const std::string& cmdLine) {
    if (cmdLine.empty() || cmdLine.find_first_not_of(' ') == std::string::npos)
        return {};

    enum State { normal, inQuote, inDoubleQuote };
    State state = normal;
    std::vector<std::string> result;
    std::string current;
    bool lastTokenHasBeenQuoted = false;

    std::istringstream stream(cmdLine);
    char ch;

    while (stream.get(ch)) {
        switch (state) {
            case inQuote:
                if (ch == '\'') {
                    lastTokenHasBeenQuoted = true;
                    state = normal;
                } else
                    current += ch;

                break;
            case inDoubleQuote:
                if (ch == '"') {
                    lastTokenHasBeenQuoted = true;
                    state = normal;
                } else
                    current += ch;

                break;
            default:
                if (ch == '\'')
                    state = inQuote;
                else if (ch == '"')
                    state = inDoubleQuote;
                else if (ch == ' ') {
                    if (lastTokenHasBeenQuoted || !current.empty()) {
                        result.push_back(current);
                        current.clear();
                    }
                } else
                    current += ch;

                lastTokenHasBeenQuoted = false;
                break;
        }
    }

    if (lastTokenHasBeenQuoted || !current.empty())
        result.push_back(current);

    if (state != normal)
        throw ApplicationError("unbalanced quotes: " + cmdLine);

    return result;
}