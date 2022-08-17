#include "agent.hpp"
#include "honeybee.hpp"

HoneyBee::HoneyBee() {
    pos_x = 0;
    pos_y = 0;
}

HoneyBee::HoneyBee(float x, float y) {
    pos_x = x;
    pos_y = y;
}

void HoneyBee::update(Environment env) {
    if (target == nullptr) { 
        vel_x = (rand() % 3 - 1) * 0.1;
        vel_y = (rand() % 3 - 1) * 0.1;
    }
    pos_x += vel_x;
    pos_y += vel_y;
}

void HoneyBee::draw(sf::RenderWindow &window) {
    sf::CircleShape c;
    c.setPosition(pos_x * 10, pos_y * 10);
    c.setRadius(5);
    c.setFillColor(sf::Color::White);
    window.draw(c);
}