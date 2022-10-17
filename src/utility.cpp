/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file utility.cpp
 * @brief File containing utility functions used throughout the project. 
 * @date 2022-10-04
 */

#include "utility.hpp"

/**
 * @brief Updates attribute of the Metrics struct (representing simulation metrics) from current time and environment status.
 * 
 * @param env Current simulation environment
 * @param time Simulation time
 */
void Metrics::updateMetrics(Environment&env, sf::Time time) {
    secs_elapsed = time.asSeconds();
    days = secs_elapsed / 86400;
    hours = (secs_elapsed / 3600) % 24;
    mins = (secs_elapsed / 60) % 60;
    secs = secs_elapsed % 60;
    hive_nectar = env.getHive()->getNectar();
    pollinated_count = env.getPollinatedCount();
}

/**
 * @brief Returns the time stored in the struct as a string
 * 
 * @return std::string representing time in format "0d : 0h : 0m : 0s"
 */
std::string Metrics::timeString() {
    std::string res = std::to_string(days)  + "d : " +
                      std::to_string(hours) + "h : " +
                      std::to_string(mins)  + "m : " +
                      std::to_string(secs)  + "s";
    return res;
}

/// @brief Prints the metrics status to console
void Metrics::toConsole() {
    std::string s = "Simulation running for " + timeString() + 
                    " , Nectar in Hive: " + std::to_string(hive_nectar) + 
                    ", Flowers Pollinated: " + std::to_string(pollinated_count);
    std::cout << s;

    for (int i=0; i<s.length(); i++) {
        std::cout << "\b";
    }

    std::cout << std::flush;
}

/// @brief  Appends data - time elapsed, hive nectar and pollination count - to the specified file.
/// @param filename Input filename of file for storing data
void Metrics::toFile(std::string filename) {
    std::ofstream out;

    out.open(filename, std::ios::out | std::ios::app);

    out << secs_elapsed     << ","
        << hive_nectar      << ","
        << pollinated_count 
        << std::endl;

    out.close();
}

/// @brief Rewrites the specified file with data - time elapsed, hive nectar and pollination count.
/// @param filename Input filename of file for storing data
void Metrics::createDataFile(std::string filename) {
    std::fstream out;

    out.open(filename, std::ios::out | std::ios::trunc);
    
    out << "time"       << ","
        << "nectar"     << ","
        << "pollinated"
        << std::endl;

    out.close();
};

#define DIMS_MAX 400
#define SCALE_MAX 50 
#define BEES_MAX 10000

/**
 * @brief A function for restricting patameter elements to realistic/optimal values.
 * Limits were defined according to simulation perfornace limits and basic reason such as having dimensions > 0. 
 * 
 */
void Parameters::check_limits(){
    if (rows < 1) rows = 1;
    if (rows > DIMS_MAX) rows = DIMS_MAX;

    if (columns < 1) columns = 1;
    if (columns > DIMS_MAX) columns = DIMS_MAX;

    if (scale < 1) scale = 1;
    if (scale > SCALE_MAX) scale = SCALE_MAX;

    if (bees < 0) bees = 0;
    if (bees > BEES_MAX) bees = BEES_MAX;

    if (soybean_p < 0) soybean_p = 0.05;
    if (soybean_p > 1) soybean_p = 1;
}

///@brief Construct a new Env Colours object with default environment colours
EnvColours::EnvColours() {
    soybeanColour = std::make_shared<sf::Color>(0, 50, 35);  // dark green
    nectarColour = std::make_shared<sf::Color>(187, 205, 17);  // light soybean-colour green
    pollenColour = std::make_shared<sf::Color>(247, 215, 90);   // yellow
    hiveColour = std::make_shared<sf::Color>(255, 0, 0);  // bright red
    locationColour = std::make_shared<sf::Color>(104, 78, 59);  // brown
}

/// @brief Construct a new SoybeanOverlays object
SoybeanOverlays::SoybeanOverlays() {
    nectar = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>(sf::Vector2f(1,1)));
    pollen = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>(sf::Vector2f(1,1)));
}