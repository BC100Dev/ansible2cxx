# Ansible to C/C++ (ansible2cxx)
ansible2cxx is a tool that converts and runs the Ansible scripts on the native layer
instead of Python, which is the language that Ansible is written in. It transforms
Ansible scripts into equivalent C/C++ source code, enabling the compilation of
executables, shared libraries, or static libraries. Moreover, it offers native-level
interpretation of Ansible scripts, providing an alternative execution path.

## Features
- **Ansible to C/C++ Translation:** Converts Ansible playbooks and roles into
  compilable C/C++ code.
- **Code Generation:** Produces source code files for various C/C++ compilers,
  especially MinGW C/C++ compilers.
- **Executable Creation:** Builds standalone executables from translated Ansible
  scripts.
- **Library Generation:** Creates shared or static libraries for integration into
  other projects.
- **Native Interpretation:** Executes Ansible scripts directly without the need for
  Ansible runtime.
- **Community Repository:** Offers the ability to run pre-existing community-driven
  tools on the native level

## Longer Description
Coming soon due to maintenance and still being under development

## Building from source
### Adding toolchains
To add a new toolchain, run this specific command:

```bash
./scripts/MakeToolchain.sh
```

It will give you a prompt for a name, and what compilers you will be using with.
That name will be the same that you will give to the `cmake` command. Example being:

```bash
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release -DAPP_CONFIG_TARGET=MyToolchain -S .. -B .
```

Replace `MyToolchain` with the name that you gave to your Toolchain.