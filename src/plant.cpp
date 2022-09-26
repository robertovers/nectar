#include "plant.hpp"

Plant::~Plant() { }

Plant::Plant(int x, int y, shared_ptr<sf::Color> colour) : Location(x, y, colour) {
    nectar = std::rand() % MAX_NECTAR + 1;
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
    float amount = 1;
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
    // add offset to existin translations
    states.transform.translate(sf::Vector2f(x, y));

    // draw base plant
    sprite->setFillColor(*colour);
    target.draw(*sprite, states);

    // add nectar overlay
    sf::Color newColour = nectarOverlay->getFillColor();
    newColour = newColour - sf::Color(0, 0, 0, 255); // reset transparency to transparent
    auto transparency = 255 * nectarPercentage(); // set transparency based on nectar value
    newColour = newColour + sf::Color(0,0,0, transparency); 
    nectarOverlay->setFillColor(newColour);
    target.draw(*nectarOverlay, states);

    // add pollen overlay
    if (isPollinated()) {
        target.draw(*pollinatedOverlay, states);
    }
}
