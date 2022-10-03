#include "location.hpp"
#include "location.hpp"
#include "location.hpp"
#include "agent.hpp"


Location::Location() : Location(0, 0) { }

Location::Location(int x, int y) : Location (x, y, std::make_shared<sf::Color>(sf::Color::Black)) { }

Location::Location(int x, int y, shared_ptr<sf::Color> colour) : x(x), y(y), colour(colour) {
    id = ID::generateID();
    auto rectangle = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>());
    rectangle->setFillColor(*colour);
    rectangle->setSize(sf::Vector2f(1, 1));
    sprite = rectangle;
}

void Location::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // add offset to existing transformations
    states.transform.translate(sf::Vector2f(x, y));
    
    sprite->setFillColor(*colour);

    target.draw(*sprite, states);
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

bool Location::isPlant() {
    return false;
}