#ifndef hive_hpp
#define hive_hpp

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Hive : public Location {
    public:
        Hive() : Hive(0, 0) { };
        Hive(int x, int y);
        void draw(sf::RenderWindow& window) override;
        bool isPlant() override;
        void depositNectar(float amount);
        float getNectar();
    private:
        float nectar;
};

#endif