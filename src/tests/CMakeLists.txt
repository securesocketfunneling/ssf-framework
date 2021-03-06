project(RUN_TESTS CXX)

enable_testing()
  
include_directories(
  ${OpenSSL_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS})

include_directories(
  ${SSF_FRAMEWORK_GTEST_ROOT_DIR}/include
)

file(GLOB_RECURSE SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES
      "${SSF_FRAMEWORK_SRC_DIR}/tests/*.h")

# --- Queue tests
add_target("queue_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "queue_tests.cpp"
)

# --- Physical layer tests
add_target("physical_layer_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "physical_layer_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
)

# --- Link layer tests
add_target("link_layer_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "link_layer_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
)

# --- Interface layer tests
add_target("interface_layer_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "interface_layer_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
)

# --- Routing layer tests
add_target("routing_layer_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "routing_layer_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
)

# --- Transport layer tests
add_target("transport_layer_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "transport_layer_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
)

# --- Interface System tests
add_target("interfaces_system_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "interfaces_system_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
    ${SSF_FRAMEWORK_INTERFACES_SYSTEM_FILES}
)

# --- Router System tests
add_target("router_system_tests"
  TYPE
    executable ${SSF_FRAMEWORK_EXEC_FLAG} TEST
  LINKS 
    ${OpenSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${SSF_FRAMEWORK_PLATFORM_SPECIFIC_LIB_DEP}
    lib_ssf_network
  PREFIX_SKIP     .*/src
  HEADER_FILTER   "\\.h(h|m|pp|xx|\\+\\+)?" 
  FILES
    "router_system_tests.cpp"
    ${SSF_FRAMEWORK_LAYER_TEST_FIXTURES_FILES}
    ${SSF_FRAMEWORK_INTERFACES_SYSTEM_FILES}
    ${SSF_FRAMEWORK_ROUTERS_SYSTEM_FILES}
)
