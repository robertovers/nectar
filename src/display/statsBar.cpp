#include "statsBar.hpp"
#include <iostream>
#include <windows.h>

StatsBar::StatsBar(shared_ptr<Metrics> metrics) {
    this->metrics = metrics;
    //view.reset(sf::FloatRect(0, 0, 50, 1000));
    updateViewport(0, 0);
    font.loadFromFile("Roboto-Regular.ttf"); 
    //  TODO: error handling
   /* char result[MAX_PATH];
    std::cout << std::string(result, GetModuleFileName(NULL, result, MAX_PATH));*/
    // set view to cover placeholderbar
    
}

void StatsBar::updateViewport(float windowX, float windowY) {
    sf::FloatRect simViewpont(0, .9, 1, 1);
    view.setViewport(simViewpont);
}

void StatsBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    /*auto shape = sf::RectangleShape();
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(50, 1000));
    target.draw(shape);*/

    auto hiveNectarValue = sf::Text();
    hiveNectarValue.setFont(font);
    hiveNectarValue.setString(std::to_string(metrics->hive_nectar));
    hiveNectarValue.setCharacterSize(40);
    hiveNectarValue.setFillColor(sf::Color::Blue);
    target.draw(hiveNectarValue);
}

