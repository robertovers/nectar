/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file statsWindow.hpp
 * @brief Imgui-based Statistics window class for displaying general simulation statistics
 * @date 2022-09-14
 */

#ifndef statsWindow_hpp
#define statsWindow_hpp

#include "../utility.hpp"
#include "../templates.hpp"

 /**
  * @brief Imgui-based Statistics window class for displaying general simulation statistics.
  *
  * Runtime, hive nectar count and pollinated flower count are displayed in a Imgui window when display()ed. 
  * It does not do any clearing or rendering; this needs to be handled elsewhere
  */
class StatsWindow {
    public:
        /**
         * @brief Construct a new StatsWindow object.
         * 
         * @param metrics Information about the simulation
         */
        StatsWindow(shared_ptr<Metrics> metrics);
        /**
         * @brief Draw the statistics window.
         */
        void display();
    private:
        /// @brief metrics and statistics about the simulation
        shared_ptr<Metrics> metrics;
};

#endif