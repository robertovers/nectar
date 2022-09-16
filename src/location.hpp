#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "templates.hpp"

class Agent;

class Location : public sf::Drawable {
    public:
        Location() : Location(0, 0) {};
        Location(int x, int y);
        virtual bool isPlant();
        void addAgent(Agent& a);
        void removeAgent(Agent& a);
        void clearAgents();
        int numAgents();
        int getX();
        int getY();
        int getID();
    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        int x;
        int y;
        int id;
        std::vector<std::reference_wrapper<Agent>> agents;
        shared_ptr<sf::Shape> sprite = nullptr;
};

#endif