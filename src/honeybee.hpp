#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"
#include "location.hpp"

class HoneyBee : public Agent {
    public:
        HoneyBee();
        HoneyBee(float x, float y);
        virtual void update(Environment env) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        shared_ptr<Location> scan(Environment env); 
};

#endif