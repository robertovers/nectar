#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"
#include "location.hpp"

class HoneyBee : public Agent {
    public:
        HoneyBee();
        HoneyBee(float x, float y);
        void update(Environment& env) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        shared_ptr<Location> scan(Environment env); 
    protected:
        float nectar = 0;
};

#endif