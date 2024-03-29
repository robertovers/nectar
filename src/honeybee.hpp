/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file honeybee.hpp
 * @brief A class for instances of the honeybee agent in the simulation.
 * @date 2022-09-11
 */

#ifndef honeybee_hpp
#define honeybee_hpp

#include <SFML/Graphics.hpp>
#include <deque>
#include "agent.hpp"
#include "location.hpp"
#include "plant.hpp"

enum HoneybeeBehaviour {

    /// @brief No target, looking for nectar source.
    Searching,

    /// @brief Found nectar source, moving towards it.
    Harvesting,

    /// @brief Moving towards a nectar source identified from a waggle dance.
    HarvestingNotified,

    /// @brief Collected nectar, returning to hive.
    Returning,

    /// @brief Collected nectar from rich source; will waggle dance at hive
    ReturningToDance
};

/**
 * @brief A class for instances of the honeybee agent in the simulation.
 * 
 * The Honeybee extends the Agent class, and is the primary agent of the
 * simulation. The actions of a honeybee depends on its behaviour attribute -
 * an enum that determines what the agent will do when it is updated at each
 * tick.
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
         * @brief Adds a plant to the bee's memory, and updates the queue.
         * 
         * @param plant the most-recently visited plant.
         */
        void addMemory(shared_ptr<Location> plant);

        /**
         * @brief Checks if a plant is in the bee's memory.
         * 
         * @param plant 
         * @return true if the plant is in its memory.
         * @return false if the plant is not in its memory.
         */
        bool inMemory(shared_ptr<Location> plant);

        /**
         * @brief Gets the bee's memory of visited plants.
         */
        std::deque<shared_ptr<Location>> getMemory();

        /**
         * @brief Get the bee's memory limit.
         * 
         * @return the max no. of flowers the bee can remember.
         */
        int getMemoryLimit();
        
        /**
         * @brief Get the bee's behavior type.
         * 
         * @return HoneybeeBehaviour 
         */
        HoneybeeBehaviour getBehaviour();

        /**
         * @brief Simulates the 'Waggle dance' to notify bees of a nectar source.
         * 
         * @param env a reference to the simulation environment.
         * @param hive a pointer to the hive.
         * @param loc the location to Waggle dance at.
         */
        void waggle(Environment& env, shared_ptr<Hive> hive, shared_ptr<Location> loc);

        /**
         * @brief Calls assertions for the correctness of the bee's state.
         */
        void _validateState();

    protected:

        /// @brief The amount of nectar the agent is carrying.
        float nectar = 0;

        /// @brief First-in-first-out queue of most-recently visited plants.
        std::deque<shared_ptr<Location>> memory;

        /// @brief The max no. of plants the bee will remember.
        const int memory_limit = 10;

        /// @brief The current behaviour of the honeybee.
        HoneybeeBehaviour behaviour;

        /// @brief The nectar carrying capacity of the honeybee in milligrams.
        float carry_capacity = 20;
};

#endif
