/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file agent.hpp
 * @brief Abstract class for extension by simulation agents.
 * @date 2022-09-10
 */

#ifndef agent_hpp
#define agent_hpp

#include <SFML/Graphics.hpp>
#include "environment.hpp"
#include "templates.hpp"

// Declaration instead of import to avoid circularity. See location.hpp.
class Location;

/**
 * @brief Abstract class for extension by simulation agents.
 * 
 * This is an abstract class that provides the basic functionality for an
 * agent as part of the simulation - primarily movement, which is implemented
 * using vectors.
 */
class Agent : public sf::Drawable {

    public:

        /**
         * @brief Construct a new Agent object.
         */
        Agent();

        /**
         * @brief Destroy the Agent object.
         */
        virtual ~Agent();

        /**
         * @brief Pure virtual update method - implemented by agent type. 
         * 
         * @param env a reference to the simulation environment.
         */
        virtual void update(Environment& env) = 0;

        /**
         * @brief Pure virtual draw method - implemented by agent type.
         * 
         * @param target a render target.
         * @param states states to be applied when rendering to the target.
         */
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        /**
         * @brief Get the agent's location.
         * 
         * @param env a reference to the simulation environment.
         * @return The agent's location of type shared_ptr<Location>.
         */
        shared_ptr<Location> getLocation(Environment& env);

        /**
         * @brief Get the target attribute.
         * 
         * @return The agent's target of type shared_ptr<Location>.
         */
        shared_ptr<Location> getTarget();

        /**
         * @brief Get the ID member.
         * 
         * @return An integer ID. 
         */
        int getID();

        /**
         * @brief Set the agent's target.
         * 
         * @param t a shared_ptr to a Location, to set as the target.
         */
        void setTarget(shared_ptr<Location> t);

        /**
         * @brief Sets the agent's direction_u vector to a random direction.
         */
        void moveRandomWalk();

        /**
         * @brief Sets the agent's direction_u vector towards its target.
         */
        void moveToTarget();

        /**
         * @brief Get the Pos object
         * 
         * @return sf::Vector2f 
         */
        sf::Vector2f getPos();

    protected:

        /// @brief Unique ID of the agent.
        int id;

        /// @brief A 2D vector representing the location of the agent.
        sf::Vector2f pos;

        /// @brief A 2D vector representing the direction of the agent.
        sf::Vector2f direction_u;

        /// @brief The agent's velocity - measured as tiles per update.
        float velocity = 0.2;

        /// @brief A location that the agent will move towards, or a nullptr.
        shared_ptr<Location> target = nullptr;

};

#endif