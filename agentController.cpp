#include "agentController.hpp"
#include "honeybee.hpp"

AgentController::AgentController() {
    agents = std::vector<shared_ptr<Agent>>(100);
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

void AgentController::drawAgents(sf::RenderWindow& window) {
    for (auto& a : agents) {
        if (a != nullptr) {
            a->draw(window);
        }
    }
}

void AgentController::addAgentPtr(shared_ptr<Agent> agent) {

}

void AgentController::removeAgentPtr(shared_ptr<Agent> agent) {
    auto itr_lim = agents.end(); // Auto can be replaced with shared_ptr_vector<MapObject>::iterator
    for (auto itr = agents.begin(); itr != itr_lim; ++itr) {
        if (*itr == agent){
            itr_lim--; // Decrementing it_lim to get iterator for last element in vector - Bad practice.. 
            swap(*itr, *itr_lim);
            agents.pop_back();
            break;
        } 
    }
};

void swap(auto& a, auto& b){ 
    auto temp = a;
    a = b;
    b = temp;
};