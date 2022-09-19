#ifndef hive_hpp
#define hive_hpp

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Hive : public Location {
    public:
        Hive() : Hive(0, 0) { };
        Hive(int x, int y);
        bool isPlant() override;
        void depositNectar(float amount);
        float getNectar();
    private:
        float nectar = 0;
};

#endif