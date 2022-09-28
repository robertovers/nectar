/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file location.hpp
 * @brief Base class for a single location tile.
 * @date 2022-09-19
 */

#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "templates.hpp"

// Declaration to avoid circularity.
class Agent;

/**
 * @brief Base class for a single location tile.
 *
 * A location is a single tile within the grid stored in the Environment.
 * We required discrete locations despite the continuous coordinate space so
 * we can perform operations (such as searching for plants) within a finite
 * space. 
 */
class Location : public sf::Drawable {

    public:

        /**
         * @brief Construct a new Location object.
         */
        Location();

        /**
         * @brief Construct a new Location object.
         * 
         * @param x the x-coordinate of the location.
         * @param y the y-coordinate of the location.
         */
        Location(int x, int y, shared_ptr<sf::Color> colour);

        /**
         * @brief Checks if this location is a Plant - used before type casting.
         * 
         * @return true if this location is Plant.
         * @return false if this location is not a Plant.
         */
        virtual bool isPlant();

        /**
         * @brief Adds an Agent reference to this location's agents array.
         * 
         * @param a an Agent to add.
         */
        void addAgent(Agent& a);

        /**
         * @brief Removes an Agent (if it exists) from the agents array.
         * 
         * @param a an Agent to remove.
         */
        void removeAgent(Agent& a);

        /**
         * @brief Clears (empties) the agents array.
         */
        void clearAgents();

        /**
         * @brief Gets a reference to the agents array.
         * 
         * @return A vector of reference-wrapped Agents. 
         */
        std::vector<std::reference_wrapper<Agent>>& getAgents();

        /**
         * @brief Gets the number of agents currently in this location.
         * 
         * @return an int - the number of agents.
         */
        int numAgents();

        /**
         * @brief Gets the x-coordinate of this location.
         * 
         * @return int x coordinate.
         */
        int getX();

        /**
         * @brief Gets the y-coordinate of this location.
         * 
         * @return int y coordinate.
         */
        int getY();

        /**
         * @brief Gets the ID of this location.
         * 
         * @return int ID.
         */
        int getID();

    protected:
        /**
         * @brief Renders this location to the target.
         * 
         * @param target a render target.
         * @param states states to be applied when rendering to the target.
         */
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        /// @brief This location's colour when drawn
        shared_ptr<sf::Color> colour;

        /// @brief This location's x-coordinate.
        int x;

        /// @brief This location's y-coordinate.
        int y;

        /// @brief A unique integer ID for this location.
        int id;

        /// @brief A vector of reference-wrapped Agents within in this location.
        std::vector<std::reference_wrapper<Agent>> agents;

        /// @brief The sprite to be drawn when rendering this location.
        shared_ptr<sf::Shape> sprite = nullptr;
};

#endif