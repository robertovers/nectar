#ifndef soybean_hpp
#define soybean_hpp

#include "plant.hpp"

class Soybean : public Plant {
    public:
        //Soybean() : Soybean(0, 0) {};
        Soybean(int x, int y, shared_ptr<sf::Color> colour, shared_ptr<sf::Color> nectarColour, shared_ptr<sf::Color> pollenColour);
};

#endif