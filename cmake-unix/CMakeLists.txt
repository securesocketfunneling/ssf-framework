cmake_minimum_required(VERSION 2.8)

# --- Special settings to Unix platform
if (UNIX)
  # --- Flags for compilation
  if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(SSF_FRAMEWORK_CLANG_NO_BOOST_WARNINGS "-Wno-unneeded-internal-declaration -Wno-unused-variable")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11 -stdlib=libc++ ${SSF_FRAMEWORK_CLANG_NO_BOOST_WARNINGS}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -ggdb -std=c++11 -stdlib=libc++ ${SSF_FRAMEWORK_CLANG_NO_BOOST_WARNINGS}")
    set(SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP "pthread")
  else()
    set(SSF_FRAMEWORK_GCC_NO_BOOST_WARNINGS "-Wno-long-long -Wno-unused-value -Wno-unused-local-typedefs")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++0x ${SSF_FRAMEWORK_GCC_NO_BOOST_WARNINGS}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -ggdb -std=c++0x ${SSF_FRAMEWORK_GCC_NO_BOOST_WARNINGS}")
    set(SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP "pthread" "rt" ${CMAKE_DL_LIBS})
  endif ()
endif(UNIX)

