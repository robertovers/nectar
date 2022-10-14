/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file honeybee.cpp
 * @brief A class for instances of the honeybee agent in the simulation.
 * @date 2022-09-11
 */

#include <math.h>
#include <iostream>
#include <assert.h>
#include "honeybee.hpp"
#include "plant.hpp"
#include "hive.hpp"

const float POLLINATION_CHANCE = 0.5;

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
        /// Case 1: Searching
        /// 
        /// The honeybee has no target, so it moves in a random walk until it 
        /// finds a potential nearby nectar source. Once it finds a nearby 
        /// plant, it sets it as its target and switches to the Harvesting 
        /// behaviour. 
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

        /// Case 2: Harvesting 
        /// 
        /// The honeybee has identified a nectar source, and will now either 
        /// move towards it, or search it for nectar once it has reached it.
        /// If the nectar source is rich, it returns to the Hive to notify 
        /// bees at the hive using the Waggle dance. Otherwise, it continues 
        /// searching until its nectar carrying capacity is reached.
        case HoneybeeBehaviour::Harvesting:
        case HoneybeeBehaviour::HarvestingNotified:

            found_plant = std::dynamic_pointer_cast<Plant>(cur_loc);

            if (found_plant == target) {
                addMemory(found_plant);

                if (!found_plant->isPollinated() && (rand() % 1) < POLLINATION_CHANCE) {
                    found_plant->pollinate();
                    env.incPollinatedCount();
                }

                if (found_plant->hasNectar()) {
                    nectar += found_plant->harvestNectar();

                    if (found_plant->hasLotsOfNectar() &&
                        behaviour != HoneybeeBehaviour::HarvestingNotified) {
                        // found rich nectar source
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
                    // no nectar, continue searching
                    target = nullptr;
                    behaviour = HoneybeeBehaviour::Searching;
                }
                break;

            } else {
                moveToTarget();
            }

            break;

        /// Case 3: Returning
        /// 
        /// The honeybee is now returning to the hive to deposit its nectar or
        /// notify bees about a nectar source. The Waggle dance will notify all
        /// bees within a one-tile radius of the hive, who will go out to search
        /// for the nectar source.
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

    // update location agent arrays if agent has moved tiles
    if (new_loc != nullptr && cur_loc != nullptr && new_loc != cur_loc) {
        cur_loc->removeAgent(*this);
        new_loc->addAgent(*this);
    }

    _validateState();
}

void HoneyBee::waggle(Environment& env, shared_ptr<Hive> hive, shared_ptr<Location> loc) {
    shared_ptr<Location> nearby;

    // loop over tiles within a one-tile radius of the hive
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

                        // the below is necessary in case a bee near the hive is
                        // notified of a nectar source before it can deposit its 
                        // own nectar
                        hive->depositNectar(bee.nectar);
                        bee.nectar = 0;

                        // set new target and behaviour to search for source
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

void HoneyBee::_validateState() {

    switch (behaviour)
    {
    case HoneybeeBehaviour::Searching:
        assert(target == nullptr); // A002
        assert(nectar < carry_capacity); // A005
        break;

    case HoneybeeBehaviour::Harvesting:
    case HoneybeeBehaviour::HarvestingNotified:
        assert(target != nullptr); // A001
        assert(std::dynamic_pointer_cast<Plant>(target) != nullptr); // A003
        break;

    case HoneybeeBehaviour::Returning:
        assert(target != nullptr); // A001
        assert(nectar >= carry_capacity); // A006
        assert(std::dynamic_pointer_cast<Hive>(target) != nullptr); // A004
        break;

    case HoneybeeBehaviour::ReturningToDance:
        assert(target != nullptr); // A001
        assert(std::dynamic_pointer_cast<Hive>(target) != nullptr); // A004
        break;
    }

    assert(memory.size() <= memory_limit); // A007
}