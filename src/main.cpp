#include <SFML/Graphics.hpp>
#include <filesystem>
#include <exception>
#include <iostream>
#include "application.hpp"

int main() {
    Application app;
    app.run();
    return 0;
}

/**
 * \mainpage
 * 
 * # Nectar: Honeybee simulations written in C++
 * 
 * Nectar is a simulation tool used to study Honeybee pollination behaviour. It is written in C++ and uses [SFML](https://www.sfml-dev.org/) for graphics components.
 * 
 * The project was developed as part of the final-year Computer Science project at Monash University, during 2022. The project team consists of Jireh Chen, Ethan Cheng, Lucille Grasso & Robert Overs.
 * 
 * ## Features
 * - Efficient engine capable of simulating thousands of bees
 * - Responsive UI with multiple display options and customisable colours
 * - Automatic report and documentation generation
 * 
 * ## Install
 * 
 * #### Required dependencies
 * - [CMake](https://cmake.org)
 * 
 * #### Optional dependencies
 * - [Doxygen](https://doxygen.nl/download.html) (for generating documentation)
 * - [Python](https://python.org) (for generating simulation reports)
 * 
 * ### MacOS
 * 
 * For macOS users with homebrew, both CMake and Doxygen can be installed with:
 * 
 * ```
 * brew install cmake && brew install doxygen
 * ```
 * 
 * Once CMake is installed, clone the nectar repository using:
 * 
 * ```
 * git clone https://github.com/robertovers/nectar.git
 * ```
 * 
 * ### Windows
 * 
 * For Windows, CMake binaries can be downloaded at: https://cmake.org/download/.
 * 
 * Doxygen binaries can be found at: https://doxygen.nl/download.html.
 * 
 * Once CMake is installed, clone the nectar repository using:
 * 
 * ```
 * git clone https://github.com/robertovers/nectar.git
 * ```
 * 
 * ### Linux
 * 
 * ## Usage
 * 
 * Navigate to the `nectar` directory and run:
 * 
 * ```
 * cmake -S . -B build
 * cmake --build build
 * ```
 * 
 * The executable will be contained in `build/src`, and can be run with:
 * 
 * ```
 * ./build/src/nectar
 * ```
 * 
 * Once built, the documentation can be location at `build/src/doc_doxygen`. Opening the `index.html` file within the html folder will load a webpage containing documentation for the project. Report and data files can be found in `build/src/reporting` once the simulation is complete.
 * 
 * ## Tests
 * 
 * To run tests, navigate to the build folder and run `ctest`.
 * 
 * Sample test output:
 * 
 * ```
 * ❯ ctest
 * [==========] Running 4 tests from 1 test suite.
 * [----------] Global test environment set-up.
 * [----------] 4 tests from HoneybeeTest
 * [ RUN      ] HoneybeeTest.ScanFindsPlant
 * [       OK ] HoneybeeTest.ScanFindsPlant (1 ms)
 * [ RUN      ] HoneybeeTest.MemoryIsAdded
 * [       OK ] HoneybeeTest.MemoryIsAdded (0 ms)
 * [ RUN      ] HoneybeeTest.MemoryIsLimited
 * [       OK ] HoneybeeTest.MemoryIsLimited (0 ms)
 * [ RUN      ] HoneybeeTest.MemoryIsFIFO
 * [       OK ] HoneybeeTest.MemoryIsFIFO (0 ms)
 * [----------] 4 tests from HoneybeeTest (1 ms total)
 * 
 * [----------] Global test environment tear-down
 * [==========] 4 tests from 1 test suite ran. (1 ms total)
 * [  PASSED  ] 4 tests.
 * ```
 */
