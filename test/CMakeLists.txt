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
  agentController_test.cpp
  honeybee_test.cpp
  location_test.cpp
  plant_test.cpp
  hive_test.cpp
  soybean_test.cpp
  #basicMapGenerator_test.cpp
  environment_test.cpp
)

target_link_libraries(
  nectar_test
  nectar_lib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(nectar_test)
