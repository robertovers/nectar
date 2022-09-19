/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file agentController.hpp
 * @brief A controller class that manages all agents in the simulation.
 * @date 2022-09-11
 */

#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"
#include "environment.hpp"
#include "templates.hpp"

/**
 * @brief A controller class that manages all agents in the simulation.
 * 
 * The AgentController stores pointers to all agents, and contains methods
 * that subsequently call methods in the agents - such as to update and draw. 
 */
class AgentController {

    public:

        /**
         * @brief Construct a new AgentController object.
         */
        AgentController();

        /**
         * @brief Updates the state of all agents in the controller.
         * 
         * @param env a reference to the simulation environment.
         */
        void updateAgents(Environment& env);

        /**
         * @brief Renders all agents to the target.
         * 
         * @param target a reference to a render target.
         * @param states states to be applied when rendering to the target.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states);

        /**
         * @brief Adds an agent to the controller.
         * 
         * @param agent a shared pointer to the agent to add.
         */
        void addAgent(shared_ptr<Agent> agent);

        /**
         * @brief Removes an agent from the controller.
         * 
         * @param agent a shared pointer to the agent to remove.
         */
        void removeAgent(shared_ptr<Agent> agent);

        /**
         * @brief Get a reference to the vector containing the agents.
         * 
         * @return a vector of shared pointers to agents.
         */
        vector_shared_ptr<Agent>& getAgents();

    private:

        /// @brief A vector of shared pointers to agents in the simulations.
        vector_shared_ptr<Agent> agents;
};

#endif