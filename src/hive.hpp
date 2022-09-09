#ifndef hive_hpp
#define hive_hpp

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Hive : public Location {
    public:
        Hive() : Location(0, 0) { }
        Hive(int x, int y) : Location(x, y) { }
        void draw(sf::RenderWindow& window) override;
        bool isPlant() override;
};

#endif