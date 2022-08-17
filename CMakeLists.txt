cmake_minimum_required(VERSION 3.14)
project(Insect_Sim)

set(CMAKE_CXX_STANDARD 14)

# include(FetchContent)
# FetchContent_Declare(SFML
#   GIT_REPOSITORY https://github.com/SFML/SFML.git
#   GIT_TAG 2.6.x
# )
# FetchContent_MakeAvailable(SFML)

# # Building simulator
# add_executable(
#   Insect_Sim 
#   main.cpp
#   application.cpp
#   agent.cpp
#   environment.cpp
#   location.cpp
#   mapGenerator.cpp
# )
# target_link_libraries(Insect_Sim PRIVATE sfml-graphics)
# target_compile_features(Insect_Sim PRIVATE cxx_std_17)
# if (WIN32 AND BUILD_SHARED_LIBS)
#   # copied dlls
#   add_custom_command(TARGET Insect_Sim POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Insect_Sim> $<TARGET_FILE_DIR:Insect_Sim> COMMAND_EXPAND_LISTS)
# endif()

# install(TARGETS Insect_Sim)

# Building tests
enable_testing()

#if(testing_enabled)
add_subdirectory(test)
#endif()
