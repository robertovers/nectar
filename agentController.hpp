#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "agent.hpp"

class AgentController {
    public:
        AgentController();
        void addAgent(Agent a);
        void updateAgents();
        void renderAgents(sf::RenderWindow &window);
    private:
        std::vector<Agent> agents;
};

#endif