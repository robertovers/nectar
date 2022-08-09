#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "agent.hpp"
#include "environment.hpp"

class AgentController {
    public:
        AgentController();
        void addHoneyBees();
        void updateAgents(Environment env);
        void renderAgents(sf::RenderWindow& window);
    private:
        int num_agents;
        std::vector<std::shared_ptr<Agent>> agents;
};

#endif