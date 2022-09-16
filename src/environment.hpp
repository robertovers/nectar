#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include "location.hpp"
#include "hive.hpp"
#include "templates.hpp"
#include "plant.hpp"

class Environment {
    public:
        Environment(int w, int h);
        vector2D_shared_ptr<Location>& getLocations();
        shared_ptr<Location> getLocation(int x, int y);
        shared_ptr<Hive> getHive();
        void draw(sf::RenderTarget& target, sf::RenderStates states);
        void setHive(shared_ptr<Hive> h);
        int getSize() const;
        int getWidth() const;
        int getHeight() const;
        // manually iterates through locations to count agents.
        int agentCount();
        // manually iterate through locations, counting plants
        int plantCount(); 
        void changeLocation(int x, int y, shared_ptr<Location> newLocation);
        void incPollinatedCount();
        int getPollinatedCount();
        void initLookupTable();
        opt_shared_ptr<Location> getNearbyPlant(shared_ptr<Location> loc);
    private:
        int width;
        int height;
        vector2D_shared_ptr<Location> locations;
        shared_ptr<Hive> hive;
        int pollinated_count = 0;
        opt_shared_ptr<Location> findNearbyPlant(shared_ptr<Location> loc);
        std::unordered_map<int, shared_ptr<Location>> plant_table;
};

#endif