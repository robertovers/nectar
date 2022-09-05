#ifndef PLANT_HPP
#define PLANT_HPP

#include "agent.hpp"

class Plant : public Location {
    public:
        Plant(int x, int y);
        virtual ~Plant();
        bool isPlant() override;
        void pollinate(float amount) override;
        float harvestNectar() override;
        bool hasNectar() override;
};


#endif