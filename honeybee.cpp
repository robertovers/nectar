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

void HoneyBee::update() {
    pos_x += vel_x;
    pos_y += vel_y;
}

void HoneyBee::render(sf::RenderWindow &window) {
    sf::CircleShape c;
    c.setPosition(pos_x, pos_y);
    c.setRadius(5);
    c.setFillColor(sf::Color::White);
    window.draw(c);
}