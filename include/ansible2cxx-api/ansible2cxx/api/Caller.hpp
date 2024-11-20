#ifndef ANSIBLE2CXX_CALLER_HPP
#define ANSIBLE2CXX_CALLER_HPP

#define ERR_EXEC_LINK_FAIL "__execLinkFail__"

enum PermissionLevel {
    SetUID,
    SetGID,
    Executable,
    Writable,
    Readable
};

namespace Ansible2Cxx {

    bool HavePermission(PermissionLevel level);

}

#endif //ANSIBLE2CXX_CALLER_HPP
