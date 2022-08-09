#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"

class HoneyBee : public Agent {
    public:
        HoneyBee();
        HoneyBee(float x, float y);
        virtual void update(Environment env) override;
        virtual void render(sf::RenderWindow& window) override;
};

#endif