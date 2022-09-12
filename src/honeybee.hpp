/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file honeybee.hpp
 * @brief Honeybee class for instances of the honeybee agent in the simulation.
 * @date 2022-09-11
 */

#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include <queue>
#include "agent.hpp"
#include "location.hpp"
#include "plant.hpp"

/**
 * @brief Honeybee class for instances of the honeybee agent in the simulation.
 * 
 * The Honeybee extends the Agent class. Its follows a simple behaviour - 
 * searching for nearby plants and collecting nectar from them if found,
 * then returning to the hive to deposit the nectar.
 */
class HoneyBee : public Agent {

    public:

        /**
         * @brief Construct a new Honeybee object.
         */
        HoneyBee();

        /**
         * @brief Construct a new Honey Bee object at the passed coordinates.
         * 
         * @param x a float x-coordinate, from 0 to the tile-width.
         * @param y a float y-coordinate, from 0 to the tile-height.
         */
        HoneyBee(float x, float y);

        /**
         * @brief Updates the position and state of the Honeybee agent.
         * 
         * @param env a reference to the simulation environment.
         */
        void update(Environment& env) override;

        /**
         * @brief Renders the Honeybee object to the target.
         * 
         * @param target a reference to a render target.
         * @param states states to be applied when rendering to the target.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        /**
         * @brief Searches a radius of the agent's location for a plant.
         * 
         * @param env the simulation environment.
         * @return a shared pointer to a plant, or a null pointer if none found. 
         */
        shared_ptr<Location> scanForPlants(Environment env); 

    protected:

        /// @brief The amount of nectar the agent is carrying.
        float nectar = 0;

        /// @brief A queue of most-recently visited flowers.
        std::queue<Plant> visited;

        /// @brief The max no. of flowers the bee will remember.
        const int memory_limit = 5;
};

#endif
