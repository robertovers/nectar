/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file legendsWindow.hpp
 * @brief Imgui-based window class for displaying a guide to simulation symbols
 * @date 2022-09-20
 */

#ifndef legendswindow_hpp
#define legendswindow_hpp
#include "menu.hpp"
#include "../location.hpp"
#include "../soybean.hpp"
#include "../honeybee.hpp"

 /**
  * @brief Imgui-based window class for displaying a guide to simulation symbols
  */
class LegendsWindow {
public:
    /**
     * @brief Draw the window.
     */
    void draw(int windowX, int windowY);
protected:
    ImVec2 defaultPosition = ImVec2(0, 0.5);
private:
    Soybean pollinatedSoybean;
    Soybean emptySoybean;
    Soybean fullSoybean;
    Location nothing;
    HoneyBee honeybee;
};

#endif