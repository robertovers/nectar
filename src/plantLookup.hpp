#ifndef plantlookup_hpp
#define plantlookup_hpp

#include <unordered_map>
#include "templates.hpp"
#include "location.hpp"
#include "plant.hpp"

class Environment;

class PlantLookup {
    public:
        PlantLookup(Environment env);
        void initLookupTable(Environment env);
        opt_shared_ptr<Plant> getNearbyPlant(shared_ptr<Location> loc);
    private:
        opt_shared_ptr<Plant> findNearbyPlant(shared_ptr<Location> loc, Environment env);
        std::unordered_map<int, shared_ptr<Plant>> plant_table;
};

#endif