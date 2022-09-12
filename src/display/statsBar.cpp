#include "statsBar.hpp"

StatsBar::StatsBar(shared_ptr<Metrics> metrics) {
    this->metrics = metrics;
}

void StatsBar::updateViewport(float windowX, float windowY) {
}

void StatsBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    auto shape = sf::RectangleShape();
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(0, 1000));
    target.draw(shape);
}

