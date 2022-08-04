#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"

class HoneyBee : public Agent {
    public:
        HoneyBee(float x, float y);
        virtual void update() override;
        virtual void render(sf::RenderWindow& window) override;
};

#endif