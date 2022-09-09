#include "location.hpp"
#include "location.hpp"
#include "location.hpp"
#include "agent.hpp"


Location::Location(int x, int y) : x(x), y(y) {
    auto rectangle = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>());
    rectangle->setFillColor(sf::Color::Black);
    rectangle->setSize(sf::Vector2f(1, 1));
    sprite = rectangle;
}

void Location::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    // add offset to existing transformations
    states.transform.translate(sf::Vector2f(x, y));

    target.draw(*sprite, states);
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