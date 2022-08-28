#ifndef CROSSSHAPE_CPP
#define CROSSSHAPE_CPP

#include "crossShape.hpp"

void CrossShape::setShape(float d, float x, float y) {
    m_vertices[0].position = sf::Vector2f(x - d/6,y - d/2);
    m_vertices[1].position = sf::Vector2f(x + d/6,y - d/2);
    m_vertices[2].position = sf::Vector2f(x + d/6,y - d/6);
    m_vertices[3].position = sf::Vector2f(x + d/2,y - d/6);
    m_vertices[4].position = sf::Vector2f(x + d/2,y + d/6);
    m_vertices[5].position = sf::Vector2f(x + d/6,y + d/6);
    m_vertices[6].position = sf::Vector2f(x + d/6,y + d/2);
    m_vertices[7].position = sf::Vector2f(x - d/6,y + d/2);
    m_vertices[8].position = sf::Vector2f(x - d/6,y + d/6);
    m_vertices[9].position = sf::Vector2f(x - d/2,y + d/6);
    m_vertices[10].position = sf::Vector2f(x - d/2,y - d/6);
    m_vertices[11].position = sf::Vector2f(x - d/6,y - d/6);
    m_vertices[0].color = sf::Color::Green;
}

void CrossShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable
    target.draw(m_vertices);
}


#endif