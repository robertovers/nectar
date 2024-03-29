/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file application.hpp
 * @brief Top-level class that initiates and controls the simulation.
 * @date 2022-09-10
 */

#ifndef application_hpp
#define application_hpp

#include <fstream>
#include "imgui.h"
#include "imgui-SFML.h"
#include "application.hpp"
#include "environment.hpp"
#include "basicMapGenerator.hpp"
#include "rowMapGenerator.hpp"
#include "agentController.hpp"
#include "utility.hpp"
#include "display/statsWindow.hpp"
#include "display/legendsWindow.hpp"
#include "display/simulationDisplay.hpp"

/**
 * @brief Top-level class that initiates and controls the simulation.
 * 
 * The Application class is the top of the simulation heirarchy, and contains
 * the simulation loop that calls all update and render methods.
 */
class Application {

    public:
        /**
         * @brief Construct a new Application object.
         */
        Application();

        /**
         * @brief Runs the simulation by initialising the simulation loop.
         */
        int run();

};

/**
 * @brief Function for generating reports on MacOS
 * 
 * @param params the parameters used when generating the environment that the simulation was run on
 */
void generate_report_macos(Parameters params);

/**
 * @brief Function for generating reports on Windows
 * 
 * @param params the parameters used when generating the environment that the simulation was run on
 */
void generate_report_windows(Parameters params);

#endif