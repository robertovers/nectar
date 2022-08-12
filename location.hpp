#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>

class Agent;

// Temporary Location class
class Location {
    public:
        Location() : x(0), y(0), width(0), height(0) { }
        Location(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) { }
        void render(sf::RenderWindow& window);
        void addAgent(Agent& a) { agents.push_back(a); };
        void clearAgents() { agents.clear(); };
        int numAgents() { return agents.size(); };
        int getX() { return x; };
        int getY() { return y; };
        int getWidth() { return width; }
        int getHeight() { return height; }
    private:
        int x;
        int y;
        int width;
        int height;
        std::vector<std::reference_wrapper<Agent>> agents;
};

#endif