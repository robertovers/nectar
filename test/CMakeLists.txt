cmake_minimum_required(VERSION 3.14)
project(nectar_test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20) 

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Building tests
enable_testing()

add_executable(
  nectar_test
  agent_test.cpp
  honeybee_test.cpp
  plant_test.cpp
  location_test.cpp
  agentController_test.cpp
  basicMapGenerator_test.cpp
)

# needed for agentController test's use of "new MockAgent", since mocked objects dont seem to work with make_shared
target_compile_definitions(nectar_test PUBLIC GTEST_LINKED_AS_SHARED_LIBRARY)

target_link_libraries(
  nectar_test
  nectar_lib
  GTest::gtest
  GTest::gmock_main  # used in agentController tests
)

# Code coverage

#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/test)
#include(CodeCoverage)
#append_coverage_compiler_flags()
#setup_target_for_coverage_gcovr_xml(${PROJECT_NAME}_coverage NAME coverage)

include(GoogleTest)
gtest_discover_tests(nectar_test)
