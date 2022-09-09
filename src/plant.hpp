#ifndef PLANT_HPP
#define PLANT_HPP

#include <SFML/Graphics.hpp>
#include "agent.hpp"

class Plant : public Location {
    public:
        Plant(int x, int y);
        virtual ~Plant();
        bool isPlant() override;
        bool hasNectar();
        bool isPollinated();
        void pollinate();
        float harvestNectar();
    protected:
        bool pollinated = false;
        float nectar = 1;
};


#endif