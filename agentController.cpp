#include "agentController.hpp"

AgentController::AgentController() {

}

void AgentController::addAgent(Agent& a) {
    agents.push_back(a);
}

void AgentController::updateAgents() {
    for (auto& a : agents) {
        a.get().update();
    }
}

void AgentController::renderAgents(sf::RenderWindow& window) {
    for (auto& a : agents) {
        a.get().render(window);
    }
}