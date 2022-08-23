#ifndef SOYBEAN_HPP
#define SOYBEAN_HPP

#include "plant.hpp"
#include <SFML/Graphics.hpp>

class Soybean : public Plant{
    public:
        Soybean();
        ~Soybean();
        Soybean(float x, float y);
        virtual void update(Environment env) override;
        virtual void draw(sf::RenderWindow& window) override;
};

#endif