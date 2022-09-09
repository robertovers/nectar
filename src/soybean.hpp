#ifndef SOYBEAN_HPP
#define SOYBEAN_HPP

#include "plant.hpp"
#include <SFML/Graphics.hpp>

class Soybean : public Plant {
    public:
        Soybean() : Soybean(0, 0) {};
        Soybean(int x, int y);
        virtual void tick();
        virtual bool isPlant() override;
};

#endif