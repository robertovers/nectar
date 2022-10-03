cmake_minimum_required(VERSION 3.14)
project(nectar)

# allow auto type parameters
set(CMAKE_CXX_STANDARD 20)
set(MSVC_VERSION 1920)

################################################################################
# Libraries
################################################################################
 
include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)

FetchContent_MakeAvailable(SFML)

# for UI
FetchContent_Declare(imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG master # previously used: v1.87 
)
FetchContent_MakeAvailable(imgui)
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml.git
  GIT_TAG master  # previously used: v2.5
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" ON)

FetchContent_MakeAvailable(imgui-sfml)

# library, for reuse with tests
add_library(
  nectar_lib STATIC 
  agent.cpp
  agentController.cpp
  basicMapGenerator.cpp
  "display/simulationDisplay.cpp"
  "display/statsWindow.cpp"
  environment.cpp
  hive.cpp
  honeybee.cpp
  location.cpp
  plant.cpp
  rowMapGenerator.cpp
  soybean.cpp
  plant.cpp
  utility.cpp
  "display/simulationDisplay.cpp"
  "display/statsWindow.cpp" 
  "display/menu.cpp"
  "display/legendsWindow.cpp")

target_link_libraries(nectar_lib PUBLIC sfml-graphics)
target_link_libraries(nectar_lib PUBLIC ImGui-SFML::ImGui-SFML)

# Build simulator
add_executable(
  nectar 
  main.cpp
  application.cpp
)

target_link_libraries(nectar PUBLIC nectar_lib)
target_compile_features(nectar PRIVATE cxx_std_17)

# add report generation directory
add_custom_command(
  TARGET nectar POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/src/reporting/ $<TARGET_FILE_DIR:nectar>/reporting/
)

# copy SFML dlls, for windows
if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(
    TARGET nectar POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:nectar> $<TARGET_FILE_DIR:nectar> COMMAND_EXPAND_LISTS
  )
endif()

# copy icon image
add_custom_command(
    TARGET nectar POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}"/src/img/bee_hex.png" $<TARGET_FILE_DIR:nectar> COMMAND_EXPAND_LISTS
  )

################################################################################
# Doxygen documentation
################################################################################

option(BUILD_DOC "Build documentation with Doxygen" ON)

find_package(Doxygen)

if (DOXYGEN_FOUND)
  set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/Doxyfile.in)
  set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
  message("Doxygen build started")

  add_custom_target(
    doc_doxygen ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM 
  )

else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

################################################################################
# Install
################################################################################

install(TARGETS nectar)
