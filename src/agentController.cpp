/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file agentController.cpp
 * @brief A controller class that manages all agents in the simulation.
 * @date 2022-09-11
 */

#include "agentController.hpp"
#include "honeybee.hpp"

AgentController::AgentController() {
    agents = std::vector<shared_ptr<Agent>>(0);
}

void AgentController::updateAgents(Environment& env) {
    for (auto& a : agents) {
        if (a != nullptr) {
            a->update(env);
        }
    }
}

void AgentController::draw(sf::RenderTarget & target, sf::RenderStates states) {
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