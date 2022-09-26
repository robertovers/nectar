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
#include "../utility.hpp"

 /**
  * @brief Imgui-based window class for displaying a guide to simulation symbols
  */
class LegendsWindow {
public:
    LegendsWindow(EnvColours envColours) : envColours(envColours) {};
    /**
     * @brief Draw the window.
     */
    void draw(int windowX=-1, int windowY=-1);
protected:
    ImVec2 defaultPosition = ImVec2(0, 0.5);
private:
    ImVec4 colorToImVec4(sf::Color color);
    sf::Color ImVec4ToColor(ImVec4 vector);
    void copyColor(sf::Color oldColour, sf::Color newColour);
    EnvColours envColours;
};

#endif