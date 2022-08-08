#include <memory>
#include "agentController.hpp"
#include "honeybee.hpp"

AgentController::AgentController(int n) {
    num_agents = n;
    agents = std::vector<std::shared_ptr<Agent>>(num_agents);
}

void AgentController::addHoneyBees() {
    for (auto& a : agents) {
        a = std::make_shared<HoneyBee>();
    }
}

void AgentController::updateAgents() {
    for (auto& a : agents) {
        if (a != NULL) {
            a->update();
        }
    }
}

void AgentController::renderAgents(sf::RenderWindow& window) {
    for (auto& a : agents) {
        if (a != NULL) {
            a->render(window);
        }
    }
}