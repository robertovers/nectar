#ifndef SOYBEAN_HPP
#define SOYBEAN_HPP

#include "plant.hpp"
#include <SFML/Graphics.hpp>

class Soybean : public Plant{
    public:
        Soybean();
        ~Soybean();
        virtual void tick();
        void draw(sf::RenderWindow& window);
        //virtual void draw(sf::RenderWindow& window);
};

#endif