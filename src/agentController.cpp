#include "agentController.hpp"
#include "honeybee.hpp"

AgentController::AgentController() {
    agents = std::vector<shared_ptr<Agent>>(0);
}

void AgentController::addHoneyBees(Environment env) {
    int rand_x, rand_y;
    for (auto& a : agents) {
        rand_x = rand() % env.getWidth();
        rand_y = rand() % env.getHeight();
        a = std::make_shared<HoneyBee>(rand_x, rand_y);
    }
}

void AgentController::updateAgents(Environment env) {
    for (auto& a : agents) {
        if (a != nullptr) {
            a->update(env);
        }
    }
}

void AgentController::drawAgents(sf::RenderTarget & target, sf::RenderStates states) {
    for (auto& a : agents) {
        if (a != nullptr) {
            a->draw(target, states);
        }
    }
}

vector_shared_ptr<Agent>& AgentController::getAgents() {
    return agents;
}

void AgentController::addAgent(shared_ptr<Agent> agent) {
    agents.push_back(agent);
}

void AgentController::removeAgent(shared_ptr<Agent> agent) {
    int id_a = agent->getID();
    auto equal_id = [id_a](shared_ptr<Agent> b) { return b->getID() == id_a; };
    auto it = std::remove_if(agents.begin(), agents.end(), equal_id);
    if (it != agents.end()) agents.erase(it);
}