#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <SFML/Graphics.hpp>
#include "agent.hpp"
#include "environment.hpp"
#include "templates.hpp"

class AgentController {
    public:
        AgentController();
        void addHoneyBees(Environment env);
        void updateAgents(Environment env);
        void draw(sf::RenderTarget & target, sf::RenderStates states);
        void addAgent(shared_ptr<Agent> agent);
        void removeAgent(shared_ptr<Agent> agent);
        vector_shared_ptr<Agent>& getAgents();
    private:
        // int num_agents;
        vector_shared_ptr<Agent> agents;
};

#endif