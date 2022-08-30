cmake_minimum_required(VERSION 3.14)
project(Insect_Sim)

# allow auto type parameters
set(CMAKE_CXX_STANDARD 20)
set(MSVC_VERSION 1920)

include(FetchContent)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

# Build simulator
add_executable(
  Insect_Sim 
  main.cpp
  application.cpp
  agent.cpp
  environment.cpp
  location.cpp
  mapGenerator.cpp
  agentController.cpp
  honeybee.cpp
  soybean.cpp
  plant.cpp
)
target_link_libraries(Insect_Sim PRIVATE sfml-graphics)
target_compile_features(Insect_Sim PRIVATE cxx_std_17)

# copy SFML dlls, for windows
if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(TARGET Insect_Sim POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Insect_Sim> $<TARGET_FILE_DIR:Insect_Sim> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Insect_Sim)