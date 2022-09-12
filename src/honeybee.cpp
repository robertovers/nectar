/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file honeybee.cpp
 * @brief Honeybee class for instances of the honeybee agent in the simulation.
 * @date 2022-09-11
 */

#include <math.h>
#include "honeybee.hpp"
#include "plant.hpp"
#include "hive.hpp"

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

void HoneyBee::update(Environment& env) {

    auto cur_loc = getLocation(env);

    // Bee has no current target
    if (target == nullptr and cur_loc != nullptr) { 

        auto found = scanForPlants(env);

        if (found == nullptr) {
            moveRandomWalk();
        } else {
            target = found;
        }

    // Bee has located its target
    } else if (cur_loc == target) {

        // Target was the Hive; deposit nectar
        if (target == env.getHive()) {
            env.getHive()->depositNectar(nectar);
            nectar = 0;
            target = nullptr;
            moveRandomWalk();

        // Target was a plant; harvest nectar
        } else {
            auto plant = std::dynamic_pointer_cast<Plant>(cur_loc);
            if (plant) {
                nectar += plant->harvestNectar();
                if (!plant->isPollinated()) {
                    plant->pollinate();
                    env.incPollinatedCount();
                }
            }
            // Remember flower and go back to hive
            addMemory(plant);
            target = env.getHive();
        }

    // Bee has a target, but has not located it yet
    } else if (target != nullptr) {

        moveToTarget();

    } else {

        moveRandomWalk();

    }

    pos += direction_u * velocity;

    auto new_loc = getLocation(env);

    if (new_loc != nullptr && cur_loc != nullptr && new_loc != cur_loc) {
        cur_loc->removeAgent(*this);
        new_loc->addAgent(*this);
    }
}

void HoneyBee::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // add offset and direction to existing transformations
    states.transform.translate(pos);
    float angle = atan2(direction_u.y, direction_u.x) * (180.0 / 3.141592653589793238463);
    states.transform.rotate(angle);

    // draw body
    float circleRadius = 0.25;

    sf::CircleShape c;
    c.setRadius(circleRadius);
    c.setFillColor(sf::Color::White);
    c.setOrigin(sf::Vector2f(circleRadius, circleRadius));
    target.draw(c, states);
    
    // draw vector
    float vectorThickness = .05;
    float vectorLength = 1;

    sf::RectangleShape r;
    r.setFillColor(sf::Color::White);
    r.setSize(sf::Vector2f(vectorLength, vectorThickness));
    float vectorOrigin = circleRadius - vectorThickness / 2;
    target.draw(r, states);

}

shared_ptr<Location> HoneyBee::scanForPlants(Environment env) {
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
                if (loc->isPlant() && !inMemory(loc)) return loc;
            }
        }
    }
    return nullptr;
} 

void HoneyBee::addMemory(shared_ptr<Location> plant) {
    memory.push_front(plant);
    if (memory.size() > memory_limit) {
        memory.pop_back();
    }
}

bool HoneyBee::inMemory(shared_ptr<Location> plant) {
    auto it = std::find(memory.begin(), memory.end(), plant);
    return it != memory.end();
}

std::deque<shared_ptr<Location>> HoneyBee::getMemory() {
    return memory;
}