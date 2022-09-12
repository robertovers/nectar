#ifndef display_hpp
#define display_hpp

#include <SFML/Graphics.hpp>

class Display : sf::Drawable {
public:
    sf::View getView() const { return view; }
    virtual void updateViewport(float windowX, float windowY) = 0;
protected:
    sf::View view = sf::View();
};

#endif