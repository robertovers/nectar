#include "plant.hpp"
#include <iostream>

Plant::~Plant() { 
}

Plant::Plant(int x, int y, shared_ptr<sf::Color> colour, shared_ptr<sf::Color> nectarColour, shared_ptr<sf::Color> pollenColour) : Location(x, y, colour) {
    this->nectarColour = nectarColour;
    this->pollinatedColour = pollenColour;
    nectar = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / MAX_NECTAR);
}

bool Plant::isPlant() {
    return true;
}

bool Plant::isPollinated() const {
    return pollinated;
}

void Plant::pollinate() {
    pollinated = true;
}

bool Plant::hasNectar() {
    return nectar > 0;
}

float Plant::nectarPercentage() const {
    return nectar / MAX_NECTAR;
}

bool Plant::hasLotsOfNectar() {
    return nectar > MAX_NECTAR * .75;
}

float Plant::harvestNectar() {
    float amount = 0.02;
    if (nectar >= amount) {
        nectar -= amount;
        return amount;
    } else {
        float harvestedNectar = nectar;
        nectar = 0;
        return harvestedNectar;
    }
}

void Plant::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // add offset to existing translations
    states.transform.translate(sf::Vector2f(x, y));

    // draw base plant
    sprite->setFillColor(*colour);
    target.draw(*sprite, states);

    // add nectar overlay
    if (nectarOverlay != nullptr) {
        sf::Color newColour = *nectarColour;
        newColour = newColour - sf::Color(0, 0, 0, 255); // reset transparency to transparent
        auto transparency = 255 * nectarPercentage(); // set transparency based on nectar value
        newColour = newColour + sf::Color(0, 0, 0, transparency);
        nectarOverlay->setFillColor(newColour);
        target.draw(*nectarOverlay, states);
    }

    // add pollen overlay
    if (pollinatedOverlay != nullptr and isPollinated()) {
        pollinatedOverlay->setFillColor(*pollinatedColour);
        target.draw(*pollinatedOverlay, states);
    }
}
