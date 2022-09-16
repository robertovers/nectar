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
    behaviour = HoneybeeBehaviour::Searching;
}

HoneyBee::HoneyBee(float x, float y) {
    pos.x = x;
    pos.y = y;
    direction_u = sf::Vector2f(0, 0);
    behaviour = HoneybeeBehaviour::Searching;
}

void HoneyBee::update(Environment& env) {

    shared_ptr<Location> found;
    shared_ptr<Plant> found_plant;
    shared_ptr<Hive> hive;

    auto cur_loc = getLocation(env);

    switch (behaviour)
    {
        case HoneybeeBehaviour::Searching:
            // found = scanForPlants(env);
            // if (found != nullptr) {
            //     target = found;
            //     behaviour = HoneybeeBehaviour::Harvesting;
            // } else {
            //     moveRandomWalk();
            // }

            break;

        case HoneybeeBehaviour::Harvesting:
            found_plant = std::dynamic_pointer_cast<Plant>(cur_loc);
            if (found_plant) {
                addMemory(found_plant);
                if (found_plant->hasNectar()) {

                    nectar += found_plant->harvestNectar();
                    if (!found_plant->isPollinated()) {
                        found_plant->pollinate();
                        env.incPollinatedCount();
                    }
                    target = env.getHive();
                    behaviour = HoneybeeBehaviour::Returning;

                } else {
                    behaviour = HoneybeeBehaviour::Searching;
                }
            } else {
                moveToTarget();
            }

            break;

        case HoneybeeBehaviour::Returning:
            hive = std::dynamic_pointer_cast<Hive>(cur_loc);
            if (hive) {
                hive->depositNectar(nectar);
                target = nullptr;
                behaviour = HoneybeeBehaviour::Searching;
            } else {
                moveToTarget();
            }

            break;
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

int HoneyBee::getMemoryLimit() {
    return memory_limit;
}