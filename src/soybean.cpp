/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file soybean.cpp
 * @brief Class representing a Location containing a soybean plant
 * @date 2022-10-04
 */

#include "soybean.hpp"

Soybean::Soybean(int x, int y, shared_ptr<sf::Color> colour, shared_ptr<sf::Color> nectarColour, shared_ptr<sf::Color> pollenColour, SoybeanOverlays soybeanOverlays) : Plant(x, y, colour, nectarColour, pollenColour) {
    // set up overlays
    pollinatedOverlay = soybeanOverlays.pollen;
    nectarOverlay = soybeanOverlays.nectar;
}