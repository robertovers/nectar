/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file environment.hpp
 * @brief A class that stores and manages a 2D grid of Location objects.
 * @date 2022-09-18
 */

#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include "location.hpp"
#include "hive.hpp"
#include "templates.hpp"
#include "plant.hpp"

/**
 * @brief A class that stores and manages a 2D grid of Location objects.
 * 
 * The simulation environment is represented as a discrete 2D grid of Locations,
 * overlaying a continuous coordinate space. This allows for efficiency in
 * tracking the agents and performing operations related to their location,
 * whilst maintaining smooth, continous agent movement.
 */
class Environment {

    public:

        /**
         * @brief Construct a new Environment object.
         * 
         * @param w width in tiles
         * @param h height in tiles
         */
        Environment(int w, int h);
        /**
         * @brief Renders the environment to the target.
         * 
         * @param target a reference to a render target.
         * @param states states to be applied when rendering to the target.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states);

        /**
         * @brief Initialises the nearby-plant lookup table for all locations.
         */
        void initLookupTable();

        /**
         * @brief Gets a nearby plant from the lookup table, using ID as key. 
         * 
         * @param loc a location. 
         * @return a shared pointer to a nearby plant if one exists, else nullptr.
         */
        opt_shared_ptr<Location> getNearbyPlant(shared_ptr<Location> loc);

        /**
         * @brief Set the Hive object.
         * 
         * @param h a shared pointer to a hive object.
         */
        void setHive(shared_ptr<Hive> h);

        /**
         * @brief Get the Size object.
         * 
         * @return an int - the size (in tiles) of the environment.
         */
        int getSize() const;

        /**
         * @brief Get the Width object
         * 
         * @return an int - the width (in tiles) of the environment.
         */
        int getWidth() const;

        /**
         * @brief Get the Height object
         * 
         * @return an int - the height (in tiles) of the environment.
         */
        int getHeight() const;

        /**
         * @brief Manually iterates through locations to count agents.
         * 
         * @return an int - the number of agents.
         */
        int agentCount();

        /**
         * @brief Manually iterates through locations to count plants.
         * 
         * @return an int - the number of plants.
         */
        int plantCount(); 

        /**
         * @brief Changes the location at the given coordinates to another.
         * 
         * @param x the x-coordinate of the location to change.
         * @param y the y-coordinate of the location to change.
         * @param newLocation a shared pointer to the new location.
         */
        void changeLocation(int x, int y, shared_ptr<Location> newLocation);
        
        /**
         * @brief Increment the number of pollinated plants.
         */
        void incPollinatedCount();

        /**
         * @brief Get the number of pollinated plants. 
         * 
         * @return an int - the number of pollinated plants.
         */
        int getPollinatedCount();

        /**
         * @brief Get the Locations object
         * 
         * @return vector2D_shared_ptr<Location>& 
         */
        vector2D_shared_ptr<Location>& getLocations();

        /**
         * @brief Get the Location object at the given coordinates.
         * 
         * @param x an int x-coordinate.
         * @param y an int y-coordinate.
         * @return a shared pointer to the corresponding location tile. 
         */
        shared_ptr<Location> getLocation(int x, int y);

        /**
         * @brief Get the Hive object.
         * 
         * @return a shared pointer to the hive. 
         */
        shared_ptr<Hive> getHive();

    private:

        /** 
         * @brief Used when initialising the lookup table, to find nearby plants.
         * 
         * @param loc a location to find a nearby plant for.
         * @return a shared pointer to a plant within a two-tile radius tiles.
         */
        opt_shared_ptr<Location> findNearbyPlant(shared_ptr<Location> loc);

        /// @brief A lookup table of nearby plants, for every location.
        std::unordered_map<int, shared_ptr<Location>> plant_table;

        /// @brief The width of the environment in location tiles.
        int width;

        /// @brief The height of the environment in location tiles.
        int height;

        /// @brief A 2D vector of all location objects in the environment.
        vector2D_shared_ptr<Location> locations;

        /// @brief The environment's hive object.
        shared_ptr<Hive> hive;

        /// @brief The number of pollinated plants.
        int pollinated_count = 0;
};

#endif