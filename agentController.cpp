#include "agentController.hpp"
#include "honeybee.hpp"

AgentController::AgentController() {
    agents = std::vector<std::shared_ptr<Agent>>(100);
}

void AgentController::addHoneyBees() {
    for (auto& a : agents) {
        a = std::make_shared<HoneyBee>();
    }
}

void AgentController::updateAgents(Environment env) {
    for (auto& a : agents) {
        if (a != NULL) {
            a->update(env);
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