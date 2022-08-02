#include <SFML/Graphics.hpp>
#include "agent.hpp"

Agent::Agent(float x, float y) {
    pos_x = x;
    pos_y = y;
}

void Agent::update() {
    pos_x += vel_x;
    pos_y += vel_y;
}

void Agent::render(sf::RenderWindow &window) {

}