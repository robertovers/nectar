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
        shared_ptr<Hive> getHive();
        void draw(sf::RenderWindow &window);
        void setHive(shared_ptr<Hive> h);
        int getSize();
        int getWidth();
        int getHeight();
        // manually iterates through locations to count agents.
        int agentCount();
        // manually iterate through locations, counting plants
        int plantCount(); 
        void changeLocation(int x, int y, shared_ptr<Location> newLocation);
        void incPollinatedCount();
        int getPollinatedCount();
    private:
        int width;
        int height;
        vector2D_shared_ptr<Location> locations;
        shared_ptr<Hive> hive;
        int pollinated_count = 0;
};

#endif