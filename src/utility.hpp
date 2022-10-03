/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file utility.hpp
 * @brief Utility class for functions used in loggin metrics and simulation configuration.
 * @date 2022-09-11
 */

#ifndef utility_hpp
#define utility_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include "environment.hpp"

struct Metrics {
    int days;
    int hours;
    int mins;
    int secs;
    float hive_nectar;
    float pollinated_count;

    void updateMetrics(Environment& env, sf::Time time);
    std::string timeString();
    void toConsole();
};

/**
 * @brief Parameters structure for storing simulation parameter values.
 * 
 */
struct Parameters {

    /**
     * @brief Construct a new Parameters object.
     * 
     */
    Parameters();   

    /**
     * @brief Number of rows for the simulation map. 
     * 
     * Note: Each grid on the map represents space required for a single crop
     */
    int rows;

    /**
     * @brief Number of columns for the simulation map. 
     * 
     * Note: Each grid on the map represents space required for a single crop
     */
    int columns;

    /**
     * @brief Scale of each grid on the simulation map. 
     * 
     * Note: Does not currently affect flight speed 
     */
    int scale;

    /**
     * @brief Number of bees to use in the simulation.
     * 
     */
    int bees;

    /**
     * @brief Probability of a soybean being planted in each grid from 0-1.
     * 
     */
    float soybean_p;

    /**
     * @brief Boolean for the exit status of the simulation conguration display 
     * 
     */
    bool normal_exit;
};

/**
 * @brief simconfigUI function for a UI display for configuring simulation parameters.
 * 
 * The simcomfigUI functions creates a display with parameters and 
 * textboxes/sliders containing the default parameter values. These
 * textboxes/slides can then be altered by the user and finalised 
 * through clicking the display simulation button. 
 * 
 * @return Parameters structure of simulation parameter values to be used.
 */
Parameters simconfigUI();

#endif