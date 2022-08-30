#ifndef SOYBEAN_CPP
#define SOYBEAN_CPP

#include "soybean.hpp"
#define GENDER 3

Soybean::~Soybean(){}

Soybean::Soybean(){
    gender=GENDER;
}

void Soybean::tick(){
}

void Soybean::draw(sf::RenderWindow& window){
    float d = 35;
    sf::ConvexShape c;
    c.setPointCount(12);
    c.setPoint(0, sf::Vector2f(x - d/6, y - d/2));
    c.setPoint(1, sf::Vector2f(x + d/6, y - d/2));
    c.setPoint(2, sf::Vector2f(x + d/6, y - d/6));
    c.setPoint(3, sf::Vector2f(x + d/2, y - d/6));
    c.setPoint(4, sf::Vector2f(x + d/2, y + d/6));
    c.setPoint(5, sf::Vector2f(x + d/6, y + d/6));
    c.setPoint(6, sf::Vector2f(x + d/6, y + d/2));
    c.setPoint(7, sf::Vector2f(x - d/6, y + d/2));
    c.setPoint(8, sf::Vector2f(x - d/6, y + d/6));
    c.setPoint(9, sf::Vector2f(x - d/2, y + d/6));
    c.setPoint(10, sf::Vector2f(x - d/2, y - d/6));
    c.setPoint(11, sf::Vector2f(x - d/6, y - d/6));
    c.setFillColor(sf::Color(100, 250, 50));
    window.draw(c);
}

#endif