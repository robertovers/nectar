#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "agent.hpp"
#include "environment.hpp"

template <typename T> using shared_ptr = std::shared_ptr<T>;
template <typename T> using vector_shared_ptr = std::vector<std::shared_ptr<T>>;

class AgentController {
    public:
        AgentController();
        void addHoneyBees();
        void updateAgents(Environment env);
        void renderAgents(sf::RenderWindow& window);
        void addAgentPtr(std::shared_ptr<Agent> agent);
        void removeAgentPtr(std::shared_ptr<Agent> agent);
    private:
        int num_agents;
        std::vector<std::shared_ptr<Agent>> agents;
};

#endif