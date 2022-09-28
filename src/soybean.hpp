#ifndef soybean_hpp
#define soybean_hpp

#include "plant.hpp"
#include "utility.hpp"

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
         */
        Soybean(int x, int y, shared_ptr<sf::Color> colour, shared_ptr<sf::Color> nectarColour, shared_ptr<sf::Color> pollenColour, SoybeanOverlays soybeanOverlays);
};

#endif