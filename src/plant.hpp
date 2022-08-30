#ifndef PLANT_HPP
#define PLANT_HPP

#include "agent.hpp"

class Plant: public Location{
    public:
        Plant();
        virtual ~Plant();
        void pollinate();
    protected:
        int gender;
        bool pollinated;
};


#endif