# Cmake Test
[![Build Status](https://github.com/kybuivan/cmake_test/actions/workflows/windows.yml/badge.svg)](https://github.com/kybuivan/cmake_test/actions)

## Building
To build Cmake Test:

1. Clone the repository:
```bash
git clone https://github.com/kybuivan/cmake_test.git
```
2. Initialize the cmake submodule recursively:
```bash
cd cmake_test
git submodule update --init --recursive
```
3. Create a build directory:
```bash
mkdir build
cd build
```
4. Run CMake:
```bash
cmake ..
```
5. Build the project:
```bash
cmake --build .
```

## License
This project is licensed under the Apache-2.0 license - see the [LICENSE](https://github.com/kybuivan/cmake_test/blob/main/LICENSE) file for details.