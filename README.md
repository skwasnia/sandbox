# Sandbox

This project is a sandbox for exercising C/C++ and CMake topics.

## Building

### Presets

```bash
$ cmake --list-presets
Available configure presets:

  "debug"   - Debug default config
  "release" - Release default config
  "dot"     - Dependency Graph Target
```

```bash
cmake --preset debug
# OR
cmake --preset release
```

### Building Targets

```bash
# Get list of targets
cmake --build build_debug --target help

# Build specific target
cmake --build build_debug --target <target_name>
```

### Manual Build

```bash
mkdir build
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Running

For convenience, there is a custom `run` target that will run a specific build
dir binary:

```bash
 cmake --build <build_folder> --target run
```

Note that `run` target depends on the executable target, thus running it will
trigger the build as well:

```bash
$ cmake --preset debug

Preset CMake variables:

  CMAKE_BUILD_TYPE="Debug"

-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /nfs/site/home/skwasnia/workarea/cmake_sandbox/build_debug

$ cmake --build build_debug --target run
[10/10] cd /nfs/site/home/skwasnia/workarea/cmake_sandbox/build_debug && /nfs/site/home/skwasnia/workarea/cmake_sandbox/build_debug/hello_world
Hello World

Interface Target

Public Target and Public Target 2 and Private Target

Public Target 2
```

### Running Manually

As an alternative one can run the binaries directly:

```bash
./build_debug/hello_world
# OR
./build_release/hello_world
```

## Cleaning

```bash
cmake --build build --target clean
```

## Dependency Graph

```bash
cmake --preset dot --graphviz=dependency.dot
# OR
cmake -S . -B dot -G Ninja --graphviz=dependency.dot

dot -Tpng dependency.dot -o dependency.png
```

## Why CMake?

<https://cmake.org/cmake/help/book/mastering-cmake/chapter/Why%20CMake.html#>

The points worth noting are:

* Build parameters in a simple, portable, text file format.
* The ability to build in a directory tree outside of the source tree.
* It generates project files for native build tools including Ninja.
* The ability to create complex, custom commands.
* The `targets` access rights feature.

## CMake Access Rights

CMake has a great feature of controlling targets access rights. The target can
be linked as PUBLIC, PRIVATE or INTERFACE. This repository is meant to
demonstrate this feature.

### Public vs. Private

Firstly, to understand the project's dependency structure one need have a look
at the graph below:

![Dependency Graph](dependency.png)

Thanks to the `cmake`, the `hello world` target can access entities in the
`publicTarget2` but not `privateTarget`. To test this one can uncomment related
lines in the main.cpp.

Please note that the same access rights apply to the include directories thus
one can control which header files are public and which are private within the
target.

### Interface Target

The INTERFACE target is a special case where the target is not actually build
but rather forward to the target that uses this interface and linked there.

This can be easily verified by looking at the Ninja Script i.e. the
`interfaceTarget.cpp` is build during the `hello_world` target's build, and
there is no `interfaceTarget.a` library being linked, where both `publicTarget`
and `publicTarget2` are linked separately.
