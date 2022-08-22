#include "agent.hpp"
#include "honeybee.hpp"
#include <iostream>

HoneyBee::HoneyBee() {
    pos.x = 0;
    pos.y = 0;
    direction_u = sf::Vector2f(0, 0);
}

HoneyBee::HoneyBee(float x, float y) {
    pos.x = x;
    pos.y = y;
    direction_u = sf::Vector2f(0, 0);
}

void HoneyBee::update(Environment env) {

    shared_ptr<Location> old_loc = getLocation(env);

    if (target == nullptr) { 
        moveRandomWalk();
    } else if (getLocation(env) == target) {
        target = nullptr;
        moveRandomWalk();
    } else {
        moveToTarget();
    }

    pos += direction_u * velocity;

    shared_ptr<Location> new_loc = getLocation(env);

    if (new_loc != old_loc) {
        old_loc->removeAgent(*this);
        new_loc->addAgent(*this);
    }
}

void HoneyBee::draw(sf::RenderWindow &window) {
    sf::CircleShape c;
    c.setPosition(pos.x * 20 - display_width/2, pos.y * 20 - display_height/2);
    c.setRadius(5);
    c.setFillColor(sf::Color::White);
    window.draw(c);

    sf::Vertex line[] = {
        sf::Vertex(pos * (float) 20),
        sf::Vertex((pos + direction_u) * (float) 20)
    };
    window.draw(line, 2, sf::Lines);
}