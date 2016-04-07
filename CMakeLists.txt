cmake_minimum_required(VERSION 2.8)
set(SSF_FRAMEWORK "SSF_FRAMEWORK")
project(${SSF_FRAMEWORK})

# --- Include CMake build components
add_subdirectory(./third_party/cmake-build-system)
include(HelpersIdeTarget)

option(SSF_FRAMEWORK_BUILD_UNIT_TESTS "Build all unit tests" OFF)

# --- Project variables
set(SSF_FRAMEWORK_BINARY_DIR "${${SSF_FRAMEWORK}_BINARY_DIR}")
set(SSF_FRAMEWORK_ROOT_DIR "${${SSF_FRAMEWORK}_SOURCE_DIR}")
set(SSF_FRAMEWORK_SRC_DIR "${SSF_FRAMEWORK_ROOT_DIR}/src")
set(SSF_FRAMEWORK_LIB_DIR "${SSF_FRAMEWORK_SRC_DIR}/lib")
set(SSF_FRAMEWORK_THIRDPARTY_DIR "${SSF_FRAMEWORK_ROOT_DIR}/third_party")

# --- Project files declaration

file(GLOB_RECURSE SSF_FRAMEWORK_COMMON_IO_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/io/*.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/io/*.cpp"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/io/*.ipp")

set(SSF_FRAMEWORK_COMMON_ERROR_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/error/error.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/error/error.ipp")

file(GLOB_RECURSE SSF_FRAMEWORK_COMMON_NETWORK_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/network/*.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/network/*.cpp"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/network/*.ipp")

file(GLOB_RECURSE SSF_FRAMEWORK_COMMON_UTILS_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/utils/*.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/network/*.ipp"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/network/*.cpp"
)

file(GLOB_RECURSE SSF_FRAMEWORK_LAYER_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/layer/*.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/layer/*.cc"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/layer/*.cpp"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/layer/*.ipp")

file(GLOB_RECURSE SSF_FRAMEWORK_INTERFACES_SYSTEM_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/system/*interface*.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/system/*interface*.cpp"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/system/*interface*.ipp")

file(GLOB_RECURSE SSF_FRAMEWORK_ROUTERS_SYSTEM_FILES
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/system/*router*.h"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/system/*router*.cpp"
    "${SSF_FRAMEWORK_SRC_DIR}/ssf/system/*router*.ipp")

set(BOOST_ROOT
      "${SSF_FRAMEWORK_THIRDPARTY_DIR}/boost" CACHE PATH "Path of boost library")
message("** BOOST_ROOT: ${BOOST_ROOT}")

set(OPENSSL_ROOT_DIR
      "${SSF_FRAMEWORK_THIRDPARTY_DIR}/openssl" CACHE PATH "Path of openssl library")
message("** OPENSSL_ROOT_DIR: ${OPENSSL_ROOT_DIR}")

# --- Include platform specific CMakeList

# ---- Third party parameters
set(SSF_FRAMEWORK_BOOST_PLATFORM_FLAGS "")
set(SSF_FRAMEWORK_BOOST_PLATFORM_COMPONENTS "")
set(SSF_FRAMEWORK_OPENSSL_PLATFORM_COMPONENTS "")

if (WIN32)
  include(./cmake-ms/CMakeLists.txt)
elseif (UNIX)
  include(./cmake-unix/CMakeLists.txt)
endif ()

# --- Define Boost version if not set
if(NOT DEP_BOOST_VERSION)
  set(DEP_BOOST_VERSION 1.56.0)
endif()

# --- Setup Boost dependencies
set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    ON)

# --- Boost components
find_package(
  Boost REQUIRED
  FLAGS
    STATIC
    ${SSF_FRAMEWORK_BOOST_PLATFORM_FLAGS}
  WITH_COMPONENTS
    system
    serialization
    program_options
    date_time
    filesystem
    coroutine
    context
    log
    regex
    thread
    chrono
    ${SSF_FRAMEWORK_BOOST_PLATFORM_COMPONENTS}
)

# --- OpenSSL components
find_package(
  OpenSSL REQUIRED
  FLAGS
    STATIC
    ${SSF_FRAMEWORK_OPENSSL_PLATFORM_FLAGS}
)

# --- Include source directory
include_directories(${SSF_FRAMEWORK_SRC_DIR})

add_subdirectory("${SSF_FRAMEWORK_SRC_DIR}/ssf")

if (SSF_FRAMEWORK_BUILD_UNIT_TESTS)
  include(GTest)

  set(GTEST_ROOT_DIR
      "${SSF_FRAMEWORK_THIRDPARTY_DIR}/gtest" CACHE PATH "Path of gtest library")

  # --- Extract GTest archive in build directory
  gtest_unpack_archive()

  set(CERT_TEST_ROOT_FILES
      "${SSF_FRAMEWORK_ROOT_DIR}/certs/certificate.crt"
      "${SSF_FRAMEWORK_ROOT_DIR}/certs/dh4096.pem"
      "${SSF_FRAMEWORK_ROOT_DIR}/certs/private.key")
  set(CERT_TEST_TRUSTED_FILES
      "${SSF_FRAMEWORK_ROOT_DIR}/certs/trusted/ca.crt"
  )

  file(GLOB_RECURSE SYSTEM_CONFIG_TEST_FILES
      "${SSF_FRAMEWORK_SRC_DIR}/tests/system/*.json")

  file(MAKE_DIRECTORY ${SSF_FRAMEWORK_BINARY_DIR}/src/tests/system)
  file(MAKE_DIRECTORY ${SSF_FRAMEWORK_BINARY_DIR}/src/tests/certs)
  file(MAKE_DIRECTORY ${SSF_FRAMEWORK_BINARY_DIR}/src/tests/certs/trusted)

  file(COPY ${SYSTEM_CONFIG_TEST_FILES} DESTINATION ${SSF_FRAMEWORK_BINARY_DIR}/src/tests/system)
  file(COPY ${CERT_TEST_ROOT_FILES} DESTINATION ${SSF_FRAMEWORK_BINARY_DIR}/src/tests/certs)
  file(COPY ${CERT_TEST_TRUSTED_FILES} DESTINATION ${SSF_FRAMEWORK_BINARY_DIR}/src/tests/certs/trusted)

  enable_testing()

  # --- Add GTest project
  add_subdirectory(${GTEST_ROOT_DIR})

  # --- Add src test
  add_subdirectory("${SSF_FRAMEWORK_SRC_DIR}/tests")
endif (SSF_FRAMEWORK_BUILD_UNIT_TESTS)
