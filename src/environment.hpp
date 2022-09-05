#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include "location.hpp"
#include "hive.hpp"
#include "templates.hpp"

class Environment {
    public:
        Environment();
        Environment(int w, int h);
        vector2D_shared_ptr<Location>& getLocations();
        shared_ptr<Location> getLocation(int x, int y);
        shared_ptr<Location>& getHive();
        void draw(sf::RenderWindow &window);
        void setHive(shared_ptr<Location> h);
        int getSize();
        int getWidth();
        int getHeight();
        // manually iterates through locations to count agents.
        int agentCount();
        // manually iterate through locations, counting plants
        int plantCount(); 
        void changeLocation(int x, int y, shared_ptr<Location> newLocation);
    private:
        int width;
        int height;
        vector2D_shared_ptr<Location> locations;
        shared_ptr<Location> hive;
};

#endif