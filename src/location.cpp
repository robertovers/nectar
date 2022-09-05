#include "agent.hpp"
#include "location.hpp"

void Location::draw(sf::RenderWindow& window) {
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(20, 20));
    r.setPosition(x * 20, y * 20);
    r.setFillColor(sf::Color::Black);
    window.draw(r);
}

bool Location::isPlant() {
    return false;
}

void Location::addAgent(Agent& a) {
    agents.push_back(a);
}

void Location::removeAgent(Agent& a) {
    int id_a = a.getID();
    auto equal_id = [id_a](Agent& b) { return b.getID() == id_a; };
    auto it = std::remove_if(agents.begin(), agents.end(), equal_id);
    if (it != agents.end()) agents.erase(it);
}

void Location::clearAgents() {
    agents.clear();
}

int Location::numAgents() {
    return agents.size();
}

int Location::getX() {
    return x;
}

int Location::getY() {
    return y;
}

void Location::pollinate(float amount) {
    pollen += 0;
}

bool Location::hasNectar() {
    return nectar > 0;
}

float Location::harvestNectar() {
    return 0;
}