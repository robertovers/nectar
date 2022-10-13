/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file soybean.hpp
 * @brief Class representing a Location containing a soybean plant
 * @date 2022-09-28
 */

#ifndef soybean_hpp
#define soybean_hpp

#include "plant.hpp"
#include "utility.hpp"

 /**
 * @brief Class representing a Location containing a soybean plant
 * 
 * Soybeans contain values and behaviours analogous to real-world soybean plants
 */
class Soybean : public Plant {

    public:
        /**
        * @brief Construct a Soybean object with the given properties
        * 
        * @param x the x-coordinate of the soybean.
        * @param y the y-coordinate of the soybean.
        * @param colour the colour of the soybean
        * @param nectarColour the colour of the nectar symbol
        * @param pollenColour the colour of the pollinated symbol
        * @param soybeanOverlays pointers to the overlays to be used by Soybeans
        */
        Soybean(int x, int y, shared_ptr<sf::Color> colour, shared_ptr<sf::Color> nectarColour, shared_ptr<sf::Color> pollenColour, SoybeanOverlays soybeanOverlays);
};

#endif