#ifndef statsbar_hpp
#define statsbar_hpp

#include "display.hpp"
#include "../templates.hpp"
#include "../utility.hpp"

class StatsBar : public Display {
public:
    StatsBar(shared_ptr<Metrics> metrics);
    void updateViewport(float windowX, float windowY);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    shared_ptr<Metrics> metrics;
    sf::Font font;
};

#endif