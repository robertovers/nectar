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

    shared_ptr<Plant> found_plant;
    opt_shared_ptr<Location> nearby_plant;
    shared_ptr<Hive> hive;

    auto cur_loc = getLocation(env);
    
    switch (behaviour)
    {
        //  
        case HoneybeeBehaviour::Searching:

            nearby_plant = env.getNearbyPlant(cur_loc);
            if (nearby_plant) {
                if (!inMemory(*nearby_plant)) {
                    target = *nearby_plant;
                    behaviour = HoneybeeBehaviour::Harvesting;
                    break;
                }
            }
            moveRandomWalk();
            break;

        //  
        case HoneybeeBehaviour::Harvesting:
        case HoneybeeBehaviour::HarvestingNotified:

            found_plant = std::dynamic_pointer_cast<Plant>(cur_loc);

            if (found_plant == target) {
                addMemory(found_plant);

                if (found_plant->hasNectar()) {
                    nectar += found_plant->harvestNectar();

                    if (!found_plant->isPollinated()) {
                        found_plant->pollinate();
                        env.incPollinatedCount();
                    }

                    if (found_plant->hasLotsOfNectar() && 
                        behaviour != HoneybeeBehaviour::HarvestingNotified) {
                        target = env.getHive();
                        behaviour = HoneybeeBehaviour::ReturningToDance;
                    }
                    else if (nectar >= carry_capacity) {
                        target = env.getHive();
                        behaviour = HoneybeeBehaviour::Returning;
                    } 
                    else {
                        target = nullptr;
                        behaviour = HoneybeeBehaviour::Searching;
                    }

                } else {
                    target = nullptr;
                    behaviour = HoneybeeBehaviour::Searching;
                }
                break;

            } else {
                moveToTarget();
            }

            break;

        // 
        case HoneybeeBehaviour::Returning:
        case HoneybeeBehaviour::ReturningToDance:

            hive = std::dynamic_pointer_cast<Hive>(cur_loc);
            if (hive) {
                hive->depositNectar(nectar);
                nectar = 0;

                if (behaviour == HoneybeeBehaviour::ReturningToDance) {
                    waggle(env, hive, memory.back());
                }

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

void HoneyBee::waggle(Environment& env, shared_ptr<Hive> hive, shared_ptr<Location> loc) {
    shared_ptr<Location> nearby;

    for (int ix=-1; ix<=1; ix++) {
        for (int iy=-1; iy<=1; iy++) {

        int tile_x = hive->getX() + ix;
        int tile_y = hive->getY() + iy;

        if ( tile_x >= 0 && tile_x < env.getWidth() &&
             tile_y >= 0 && tile_y < env.getHeight() ) 
            {
                nearby = env.getLocations()[tile_y][tile_x];

                for (auto agent : nearby->getAgents()) {
                    auto& bee = dynamic_cast<HoneyBee&>(agent.get());
                    if (bee.behaviour != HoneybeeBehaviour::HarvestingNotified) {
                        hive->depositNectar(bee.nectar);
                        bee.nectar = 0;
                        bee.target = loc;
                        bee.behaviour = HoneybeeBehaviour::HarvestingNotified;
                    }
                }
            }
        }
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
    // float vectorThickness = .05;
    // float vectorLength = 1;

    // sf::RectangleShape r;
    // r.setFillColor(sf::Color::White);
    // r.setSize(sf::Vector2f(vectorLength, vectorThickness));
    // float vectorOrigin = circleRadius - vectorThickness / 2;
    // target.draw(r, states);

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