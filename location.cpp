#include "location.hpp"

void Location::draw(sf::RenderWindow& window) {
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(10, 10));
    r.setPosition(x * 10, y * 10);
    r.setFillColor(sf::Color::Blue);
    window.draw(r);
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