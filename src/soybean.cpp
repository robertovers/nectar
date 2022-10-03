#include "soybean.hpp"
#define GENDER 3

Soybean::Soybean(int x, int y, shared_ptr<sf::Color> colour, shared_ptr<sf::Color> nectarColour, shared_ptr<sf::Color> pollenColour, SoybeanOverlays soybeanOverlays) : Plant(x, y, colour, nectarColour, pollenColour) {
    // set up overlays
    pollinatedOverlay = soybeanOverlays.pollen;
    nectarOverlay = soybeanOverlays.nectar;
}