#ifndef hive_hpp
#define hive_hpp

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Hive : public Location {
    public:
        Hive() : Hive(0, 0) { };
        Hive(int x, int y);
};

#endif