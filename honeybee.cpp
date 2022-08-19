#include "agent.hpp"
#include "honeybee.hpp"
#include <iostream>

HoneyBee::HoneyBee() {
    pos_x = 0;
    pos_y = 0;
}

HoneyBee::HoneyBee(float x, float y) {
    pos_x = x;
    pos_y = y;
}

void HoneyBee::update(Environment env) {

    shared_ptr<Location> old_loc = getLocation(env);
    
    if (target == nullptr) { 
        vel_x = (rand() % 3 - 1) * 0.1;
        vel_y = (rand() % 3 - 1) * 0.1;
    }

    pos_x += vel_x;
    pos_y += vel_y;

    shared_ptr<Location> new_loc = getLocation(env);

    if (new_loc != old_loc) {
        old_loc->removeAgent(*this);
        new_loc->addAgent(*this);
    }
}

void HoneyBee::draw(sf::RenderWindow &window) {
    sf::CircleShape c;
    c.setPosition(pos_x * 20 - 5, pos_y * 20 - 5);
    c.setRadius(5);
    c.setFillColor(sf::Color::White);
    window.draw(c);
}