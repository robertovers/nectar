#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "agent.hpp"

// Temporary Location class
class Location {
    public:
        Location(int x, int y) : x(x), y(y) { }
        void render(sf::RenderWindow& window);
        void addAgent(Agent& a) { agents.push_back(a); };
        void clearAgents() { agents.clear(); };
        int getX() { return x; };
        int getY() { return y; };
        int numAgents() { return agents.size(); };
    private:
        int x;
        int y;
        std::vector<std::reference_wrapper<Agent>> agents;
};

#endif