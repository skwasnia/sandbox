# Sandbox

This project is a sandbox for exercising C/C++ and CMake topics.

## Building

```bash
mkdir build
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Running

```bash
./build/hello_world
```
