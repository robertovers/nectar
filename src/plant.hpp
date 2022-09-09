#ifndef PLANT_HPP
#define PLANT_HPP

#include <SFML/Graphics.hpp>
#include "agent.hpp"

class Plant : public Location {
    public:
        Plant(int x, int y);
        virtual ~Plant();
        void draw(sf::RenderWindow& window) override;
        bool isPlant() override;
        bool hasNectar();
        void pollinate(float amount);
        float harvestNectar();
    protected:
        float pollen = 1;
        float nectar = 1;
};


#endif