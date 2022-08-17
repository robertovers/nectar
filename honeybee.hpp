#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"

class HoneyBee : public Agent {
    public:
        HoneyBee();
        HoneyBee(float x, float y);
        virtual void update(Environment env) override;
        virtual void draw(sf::RenderWindow& window) override;
};

#endif