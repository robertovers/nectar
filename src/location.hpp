#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>

class Agent;

class Location {
    public:
        Location() : x(0), y(0) { }
        Location(int x, int y) : x(x), y(y) { }
        virtual void draw(sf::RenderWindow& window);
        virtual bool isPlant();
        void addAgent(Agent& a);
        void removeAgent(Agent& a);
        void clearAgents();
        int numAgents();
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        virtual void pollinate(float amount);
        virtual float harvestNectar();
        virtual bool hasNectar();
    protected:
        int x;
        int y;
        std::vector<std::reference_wrapper<Agent>> agents;
        float nectar = 1;
        float pollen = 0;
};

#endif