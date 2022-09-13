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

# for UI
FetchContent_Declare(imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG master
)
FetchContent_MakeAvailable(imgui)
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml.git
  GIT_TAG        master
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" ON)

FetchContent_MakeAvailable(imgui-sfml)

# library, for reuse with tests
add_library(
  insect_lib STATIC 
  agent.cpp
  environment.cpp
  location.cpp
  basicMapGenerator.cpp
  rowMapGenerator.cpp
  agentController.cpp
  honeybee.cpp
  hive.cpp
  soybean.cpp
  plant.cpp
  "display/statsBar.cpp"
  utility.cpp
 "display/simulationDisplay.cpp")

target_link_libraries(insect_lib PUBLIC sfml-graphics)
target_link_libraries(insect_lib PUBLIC ImGui-SFML::ImGui-SFML)

# Build simulator
add_executable(
  Insect_Sim 
  main.cpp
  application.cpp
)
target_link_libraries(Insect_Sim PUBLIC insect_lib)
#target_link_libraries(Insect_Sim PRIVATE sfml-graphics)
target_compile_features(Insect_Sim PRIVATE cxx_std_17)

# copy SFML dlls, for windows
if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(TARGET Insect_Sim POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Insect_Sim> $<TARGET_FILE_DIR:Insect_Sim> COMMAND_EXPAND_LISTS)
endif()

# TODO: copy font to exe location

install(TARGETS Insect_Sim)
