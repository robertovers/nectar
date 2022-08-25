#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>

class Agent;

class Location {
    public:
        Location() : x(0), y(0) { };
        Location(int x, int y) : x(x), y(y) { }
        void draw(sf::RenderWindow& window);
        void addAgent(Agent& a);
        void removeAgent(Agent& a);
        void clearAgents();
        int numAgents();
        int getX();
        int getY();
        int getWidth();
        int getHeight();
    private:
        int x;
        int y;
        std::vector<std::reference_wrapper<Agent>> agents;
};

#endif