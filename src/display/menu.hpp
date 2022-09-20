/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file menu.hpp
 * @brief Abstract imgui-based window class  that displays within the main application window
 * @date 2022-09-20
 */

#ifndef menu_hpp
#define menu_hpp
#include "imgui.h"
#include "imgui-SFML.h"

 /**
  * @brief Abstract imgui-based window class that displays within the main application window
  */
class Menu {
public:
    /**
     * @brief Draw the window.
     */
    virtual void draw(int windowX, int windowY) = 0;
protected:
    void moveUnseenWindow(int windowX, int windowY);
    ImVec2 defaultPosition = ImVec2(0, 0);
};

#endif