#include <SFML/Graphics.hpp>
#include <filesystem>
#include <exception>
#include <iostream>
#include "application.hpp"

const std::filesystem::path report_script_macos = "reporting/generate_macos.sh";
const std::filesystem::path report_script_windows = "reporting/generate_windows.sh";

void generate_report_macos();
void generate_report_windows();

int main() {
    Application app;
    app.run();

    // #ifdef _WIN32
    //     generate_report_windows();
    // #elif __APPLE__
    //     generate_report_macos();
    // #endif

    return 0;
}

void generate_report_macos() {
    std::filesystem::permissions(report_script_macos, std::filesystem::perms::owner_all);

    try {
        system(report_script_macos.string().c_str());
    } catch (const std::exception& e) {
        std::cout << "ERROR: Failed to generate report." << std::endl;
    }
}

void generate_report_windows() {
    std::filesystem::permissions(report_script_windows, std::filesystem::perms::owner_all);

    try {
        system(report_script_windows.string().c_str());
    } catch (const std::exception& e) {
        std::cout << "ERROR: Failed to generate report." << std::endl;
    }
}

/**
 * \mainpage
 * # Nectar: Honeybee simulations written in C++
 * 
 * Nectar is a simulation tool used to study Honeybee pollination behaviour. It is written in C++ and uses [SFML](https://www.sfml-dev.org/) for graphics components.
 * 
 * The project was developed as part of the final-year Computer Science project at Monash University, during 2022. The project team consists of Jireh Chen, Ethan Cheng, Lucille Grasso & Robert Overs.
 * 
 * ## Features
 * - *TODO*
 * - *TODO*
 * - *TODO*
 * 
 * ## Install
 * 
 * *TODO: Add more detail, include UNIX.*
 * 
 * [CMake](https://cmake.org) is required to build nectar, and optionally, [Doxygen](https://doxygen.nl/download.html) for generating documentation.
 * 
 * ### macOS
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
 * ## Usage
 * 
 * *TODO: Add info about Doxygen and options.*
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
