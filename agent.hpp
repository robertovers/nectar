#ifndef agent_hpp
#define agent_hpp

#include <SFML/Graphics.hpp>
#include "environment.hpp"

class Agent {
    public:
        virtual ~Agent();
        virtual void update(Environment env) = 0;
        virtual void render(sf::RenderWindow& window) = 0;
    protected:
        float pos_x;
        float pos_y;
        float vel_x = 0;
        float vel_y = 0;
};

#endif