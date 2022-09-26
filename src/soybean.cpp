#include "soybean.hpp"
#define GENDER 3

Soybean::Soybean(int x, int y, shared_ptr<sf::Color> colour) : Plant(x, y, colour) {
    //sprite->setFillColor(*colour);

    // set up overlays
    auto pollen = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>());
    pollen->setFillColor(sf::Color(247, 215, 90));
    pollen->setSize(sf::Vector2f(.3, .3));
    pollinatedOverlay = pollen;

    auto nectar = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>());
    nectar->setFillColor(sf::Color(187, 205, 17));
    nectar->setSize(sf::Vector2f(1, 1));
    nectarOverlay = nectar;
}

//void Soybean::draw(sf::RenderTarget & target, sf::RenderStates states) {
//    /*float d = 35;
//    sf::ConvexShape c;
//    c.setPointCount(12);
//    c.setPoint(0, sf::Vector2f(x - d/6, y - d/2));
//    c.setPoint(1, sf::Vector2f(x + d/6, y - d/2));
//    c.setPoint(2, sf::Vector2f(x + d/6, y - d/6));
//    c.setPoint(3, sf::Vector2f(x + d/2, y - d/6));
//    c.setPoint(4, sf::Vector2f(x + d/2, y + d/6));
//    c.setPoint(5, sf::Vector2f(x + d/6, y + d/6));
//    c.setPoint(6, sf::Vector2f(x + d/6, y + d/2));
//    c.setPoint(7, sf::Vector2f(x - d/6, y + d/2));
//    c.setPoint(8, sf::Vector2f(x - d/6, y + d/6));
//    c.setPoint(9, sf::Vector2f(x - d/2, y + d/6));
//    c.setPoint(10, sf::Vector2f(x - d/2, y - d/6));
//    c.setPoint(11, sf::Vector2f(x - d/6, y - d/6));
//    c.setFillColor(sf::Color(100, 250, 50));
//    window.draw(c);*/
//    auto windowSize = window.getSize();
//    float width = 0;
//    // set square to fit smallest window dimension
//    if (windowSize.x < windowSize.y) {
//        width = drawWidth * windowSize.x;
//    }
//    else {
//        width = drawWidth * windowSize.y;
//    }
//    sf::RectangleShape r;
//    r.setSize(sf::Vector2f(width, width));
//    r.setPosition(x * width, y * width);
//    r.setFillColor(sf::Color(0, 50, 0));
//    window.draw(r);
//}