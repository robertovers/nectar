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

    shared_ptr<Location> cur_loc = getLocation(env);

    if (target == nullptr and cur_loc != nullptr) { 
        auto found = scan(env);
        if (found == nullptr) {
            moveRandomWalk();
        } else {
            target = found;
        }
    } else if (getLocation(env) == target) {
        target = nullptr;
        moveRandomWalk();
    } else {
        moveToTarget();
    }

    pos += direction_u * velocity;

    shared_ptr<Location> new_loc = getLocation(env);

    if (new_loc != nullptr && cur_loc != nullptr && new_loc != cur_loc) {
        cur_loc->removeAgent(*this);
        new_loc->addAgent(*this);
    }
}

shared_ptr<Location> HoneyBee::scan(Environment env) {
    auto current_loc = getLocation(env);
    auto locations = env.getLocations();

    for (int ix=-2; ix<=2; ix++) {
        for (int iy=-2; iy<=2; iy++) {
            int tile_x = current_loc->getX() + ix;
            int tile_y = current_loc->getY() + iy;
            if ( tile_x >= 0 && tile_x < env.getWidth() &&
                 tile_y >= 0 && tile_y < env.getHeight() ) 
            {
                auto loc = locations[tile_y][tile_x]; 
                if (loc->hasNectar()) return loc;
            }
        }
    }
    return nullptr;
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