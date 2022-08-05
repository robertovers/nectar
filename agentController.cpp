#include <memory>
#include "agentController.hpp"
#include "honeybee.hpp"

AgentController::AgentController(int n) {
    num_agents = n;
    agents = std::vector<std::unique_ptr<Agent>>(num_agents);
}

void AgentController::addHoneyBees() {
    for (auto& a : agents) {
        a=std::make_unique<HoneyBee>();
    }
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