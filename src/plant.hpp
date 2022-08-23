#ifndef PLANT_HPP
#define PLANT_HPP


#include "agent.hpp"

class Plant : public Agent{
    public:
        Plant();
        Plant(float x, float y);
        virtual ~Plant();
        void pollinate();
    protected:
        int gender;
        bool pollinated;
};


#endif