# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-src"
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-build"
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/jirehchen/Documents/Uni/2022 S2/FIT3162_Project/Project/fit3161-insect-simulations/src/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
