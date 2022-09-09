#ifndef soybean_hpp
#define soybean_hpp

#include "plant.hpp"

class Soybean : public Plant {
    public:
        Soybean() : Soybean(0, 0) {};
        Soybean(int x, int y);
};

#endif