#include <SFML/Graphics.hpp>
#include "agent.hpp"
#include "honeybee.hpp"

HoneyBee::HoneyBee(float x, float y) {
    pos_x = x;
    pos_y = y;
}

void HoneyBee::update() {
    pos_x += vel_x;
    pos_y += vel_y;
}

void HoneyBee::render(sf::RenderWindow &window) {

}