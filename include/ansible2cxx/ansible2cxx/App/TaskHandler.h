#ifndef ANSIBLE2CXX_TASKHANDLER_H
#define ANSIBLE2CXX_TASKHANDLER_H

#include <string>

namespace Ansible {

    class Task {
    private:
        std::string name, whenExec, notifiers;
    };

}

#endif //ANSIBLE2CXX_TASKHANDLER_H
