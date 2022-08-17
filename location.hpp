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
        void draw(sf::RenderWindow& window);
        void addAgent(Agent& a);
        void clearAgents();
        int numAgents();
        int getX();
        int getY();
        int getWidth();
        int getHeight();
    private:
        int x;
        int y;
        int width;
        int height;
        std::vector<std::reference_wrapper<Agent>> agents;
};

#endif