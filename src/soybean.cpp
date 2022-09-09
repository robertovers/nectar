#include "soybean.hpp"
#define GENDER 3

Soybean::Soybean(int x, int y) : Plant(x, y) {
    sprite->setFillColor(sf::Color(0, 50, 0));
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