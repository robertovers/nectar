#include "location.hpp"

void Location::draw(sf::RenderWindow& window) {

}

void Location::addAgent(Agent& a) {
    agents.push_back(a);
}

void Location::clearAgents() {
    agents.clear();
}

int Location::numAgents() {
    return agents.size();
}

int Location::getX() {
    return x;
};

int Location::getY() {
    return y;
}