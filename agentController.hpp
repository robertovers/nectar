#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "agent.hpp"

class AgentController {
    public:
        AgentController(int n);
        void updateAgents();
        void renderAgents(sf::RenderWindow& window);
    private:
        int num_agents;
        std::vector<std::unique_ptr<Agent>> agents;
};

#endif