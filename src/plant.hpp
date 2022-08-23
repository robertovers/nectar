#ifndef PLANT_HPP
#define PLANT_HPP


#include "agent.hpp"

class Plant : public virtual Agent{
    public:
        virtual ~Plant();
        void pollinate();
    protected:
        int gender;
        bool pollinated;
};




#endif