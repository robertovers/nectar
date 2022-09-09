#ifndef soybean_hpp
#define soybean_hpp

#include "plant.hpp"

class Soybean : public Plant {
    public:
        using Plant::Plant;
        void draw(sf::RenderWindow& window) override;
};

#endif