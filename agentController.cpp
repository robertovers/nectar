#include <memory>
#include "agentController.hpp"

AgentController::AgentController(int n) {
    num_agents = n;
    agents = std::vector<std::unique_ptr<Agent>>(num_agents);
}

void AgentController::updateAgents() {
    for (auto& a : agents) {
        a->update();
    }
}

void AgentController::renderAgents(sf::RenderWindow& window) {
    for (auto& a : agents) {
        a->render(window);
    }
}