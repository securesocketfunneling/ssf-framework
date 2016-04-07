# SSF Framework

## How to use

### Integrate as submodule

```bash
mkdir -p third_party/ssf_framework/ssf_framework
git submodule add -b master "SSF_FRAMEWORK_REPOSITORY_URL.git" third_party/ssf_framework/ssf_framework

cat > "third_party/ssf_framework/CMakeLists.txt" <<EOL

option(SSF_FRAMEWORK_BUILD_UNIT_TESTS OFF)

add_subdirectory (ssf_framework)

set_property(TARGET "lib_ssf_network" PROPERTY FOLDER "Third party/Libraries")

EOL

```

In root `CMakeLists.txt` :

```
add_subdirectory(third_party/ssf_framework)
```

Link with `lib_ssf_network` when using SSF Framework

## Build tests

### Requirements

* Winrar >= 5.2.1 (Third party builds on Windows)
* Boost >= 1.56.0
* OpenSSL >= 1.0.2
* Google Test >= 1.7.0
* CMake >= 2.8.11
* nasm (OpenSSL build on windows)
* Perl | Active Perl >= 5.20 (OpenSSL build on windows)
* C++11 compiler (Visual Studio 2013, Clang, g++, ...)

### Build on Windows

* Go in project directory

```bash
cd PROJECT_PATH
```

* Copy [Boost archive](http://www.boost.org/users/download/) in ``third_party/boost``

```bash
cp boost_1_XX_Y.tar.bz2 PROJECT_PATH/third_party/boost
```

* Copy [OpenSSL archive](https://www.openssl.org/source/) in ``third_party/openssl``

```bash
cp openssl-1.0.XY.tar.gz PROJECT_PATH/third_party/openssl
```

If you are using *openssl-1.0.2a*, you need to fix the file ``crypto/x509v3/v3_scts.c``. It contains an incorrect ``#include`` line.
Copy [the diff from OpenSSL Github](https://github.com/openssl/openssl/commit/77b1f87214224689a84db21d2eb54e9497186d93.diff)
(ignore the 2 first lines) and put it in ``PROJECT_PATH/third_party/openssl/patches``. The build script will then patch the sources.

* Copy [GTest archive](http://code.google.com/p/googletest/downloads/list) in ``third_party/gtest``

 ```bash
 cp gtest-1.X.Y.zip PROJECT_PATH/third_party/gtest
 ```

* Generate project

```bash
git submodule update --init --recursive
mkdir PROJECT_PATH/build
cd PROJECT_PATH/build
cmake -DSSF_FRAMEWORK_BUILD_UNIT_TESTS=ON ../
```

* Build tests

```bash
cd PROJECT_PATH/build
cmake --build . --target run_build_tests --config Debug|Release
```

### Build on Linux

* Go in project directory

```bash
cd PROJECT_PATH
```

* Copy [Boost archive](http://www.boost.org/users/download/) in ``third_party/boost``

```bash
cp boost_1_XX_Y.tar.bz2 PROJECT_PATH/third_party/boost
```

* Copy [OpenSSL archive](https://www.openssl.org/source/) in ``third_party/openssl``

```bash
cp openssl-1.0.XY.tar.gz PROJECT_PATH/third_party/openssl
```

* Copy [GTest archive](http://code.google.com/p/googletest/downloads/list) in ``third_party/gtest``

```bash
cp gtest-1.X.Y.zip PROJECT_PATH/third_party/gtest
```

* Generate project

```bash
git submodule update --init --recursive
mkdir PROJECT_PATH/build
cd PROJECT_PATH/build
cmake -DCMAKE_BUILD_TYPE=Release|Debug -DSSF_FRAMEWORK_BUILD_UNIT_TESTS=ON ../
```

* Build tests

```bash
cd PROJECT_PATH/build
cmake --build . --target run_build_tests -- -j
```

### Build on Mac OS X

* Go in project directory

```bash
cd PROJECT_PATH
```

* Copy [Boost archive](http://www.boost.org/users/download/) in ``third_party/boost``

```bash
cp boost_1_XX_Y.tar.bz2 PROJECT_PATH/third_party/boost
```

* Copy [OpenSSL archive](https://www.openssl.org/source/) in ``third_party/openssl``

```bash
cp openssl-1.0.XY.tar.gz PROJECT_PATH/third_party/openssl
```

* Copy [GTest archive](http://code.google.com/p/googletest/downloads/list) in ``third_party/gtest``

```bash
cp gtest-1.X.Y.zip PROJECT_PATH/third_party/gtest
```

* Generate project

```bash
git submodule update --init --recursive
mkdir PROJECT_PATH/build
cd PROJECT_PATH/build
cmake -DCMAKE_BUILD_TYPE=Release|Debug -DSSF_FRAMEWORK_BUILD_UNIT_TESTS=ON ../
```

* Build tests

```bash
cd PROJECT_PATH/build
cmake --build . --target run_build_tests
```
