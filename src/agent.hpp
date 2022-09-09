#ifndef agent_hpp
#define agent_hpp

#include <SFML/Graphics.hpp>
#include "environment.hpp"
#include "templates.hpp"
#include <iostream>

class Location;

class Agent : public sf::Drawable {
    public:
        Agent();
        virtual ~Agent();
        virtual void update(Environment& env) = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
        shared_ptr<Location> getLocation(Environment& env);
        shared_ptr<Location> getTarget();
        int generateID();
        int getID();
        void setTarget(shared_ptr<Location> t);
        void moveRandomWalk();
        void moveToTarget();
    protected:
        int id;
        sf::Vector2f pos;
        sf::Vector2f direction_u;
        float velocity = 0.2;
        shared_ptr<Location> target = nullptr;
};

#endif