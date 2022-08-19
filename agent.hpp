#ifndef agent_hpp
#define agent_hpp

#include <SFML/Graphics.hpp>
#include "environment.hpp"
#include "templates.hpp"

class Location;

class Agent {
    public:
        Agent();
        virtual ~Agent();
        virtual void update(Environment env) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        shared_ptr<Location> getLocation(Environment env);
        shared_ptr<Location> getTarget();
        int generateID();
        int getID();
    protected:
        int id;
        float pos_x;
        float pos_y;
        float vel_x = 0;
        float vel_y = 0;
        int display_width = 10;
        int display_height = 10;
        shared_ptr<Location> target = nullptr;
};

#endif