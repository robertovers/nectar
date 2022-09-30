/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file legendsWindow.hpp
 * @brief Imgui-based window class for displaying a guide to simulation symbols + options
 * @date 2022-09-20
 */

#ifndef legendswindow_hpp
#define legendswindow_hpp
#include "menu.hpp"
#include "../location.hpp"
#include "../soybean.hpp"
#include "../honeybee.hpp"
#include "../utility.hpp"

/// @brief the different options to choose between for the soybean overlays
enum OverlayOptions {
    /// @brief No overlay is displayed
    None, 
    /// @brief A small square overlay
    Small, 
    /// @brief A full-location-sized overlay
    Full
};

/**
 * @brief Imgui-based window class for displaying a guide to simulation symbols + options
 * 
 * It displays labelled colours of all types of locations in the simulation, and of the soybean pollen and nectar overlays. 
 * These colours can be modified through a color-picker. It also offers options for toggling the size of the soybean overlays: none, small and full-size.
 * Menu options are hardcoded; for example, an Environment without Soybeans or a Hive will still display related options.
 */
class LegendsWindow {
public:
    LegendsWindow(EnvColours envColours, SoybeanOverlays soybeanOverlays) : envColours(envColours), soybeanOverlays(soybeanOverlays) {};
    /**
     * @brief Draw the window.
     */
    void draw(int windowX=-1, int windowY=-1);
protected:
    /// @brief default position of the menu in the main window
    ImVec2 defaultPosition = ImVec2(0, 0.5);
private:
    /**
     * @brief Convert an sfml Colour to an equivalent imgui vector
     * 
     * @param color the colour to be converted
     * @return an imgui vector, containing the red, green, blue and alpha values divided by 255
     */
    ImVec4 colorToImVec4(sf::Color color);
    /**
     * @brief Convert an imgui vector to the equivalent sfml Color
     *
     * @param vector the vector to be converted, containing a colour's red, green, blue and alpha values divided by 255
     * @return the equivalent Color
     */
    sf::Color ImVec4ToColor(ImVec4 vector);
    /**
     * @brief Modify a given Color in place to contain the same values as another Color
     *
     * @param[out] oldColour the Color to be changed
     * @param newColour the Color to be copied
     */
    void copyColor(shared_ptr<sf::Color> oldColour, sf::Color newColour);
    /**
     * @brief Modify a given shape to a specified overlay type
     *
     * @param[out] overlay the Shape to be modified
     * @param overlayType value indicating how overlay should be changed 
     */
    void changeOverlay(std::shared_ptr<sf::Shape> overlay, OverlayOptions overlayType);

    ///@brief pointers to colours used by Locations
    EnvColours envColours;
    ///@brief pointers to the overlays used by Soybeans
    SoybeanOverlays soybeanOverlays;

    bool paused = false;
};

#endif