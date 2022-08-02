#include "agentController.hpp"

AgentController::AgentController() {

}

void AgentController::addAgent(Agent a) {
    agents.push_back(a);
}

void AgentController::updateAgents() {
    for (auto& a : agents) {
        a.update();
    }
}

void AgentController::renderAgents(sf::RenderWindow& window) {
    for (auto& a : agents) {
        a.render(window);
    }
}