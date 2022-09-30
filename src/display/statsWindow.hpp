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
#include "menu.hpp"

 /**
  * @brief Imgui-based Statistics window class for displaying general simulation statistics.
  *
  * Runtime, hive nectar count and pollinated flower count are displayed in a Imgui window when draw()n. 
  * It does not do any clearing or rendering; this needs to be handled elsewhere
  */
class StatsWindow : Menu {
    public:
        /**
         * @brief Construct a new StatsWindow object.
         * 
         * @param metrics Information about the simulation
         */
        StatsWindow(shared_ptr<Metrics> metrics);
        /**
         * @brief Draw the statistics window.
         * 
         * @param windowX The width of the window that the Stats Window will be drawn to, in pixels. -1 if not specified
         * @param windowY The height of the window that the Stats Window will be drawn to, in pixels. -1 if not specified
         */
        void draw(int windowX = -1, int windowY = -1) override;
    private:
        /// @brief metrics and statistics about the simulation
        shared_ptr<Metrics> metrics;
};

#endif