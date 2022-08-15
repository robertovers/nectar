#ifndef MAPOBJECT_HPP
#define MAPOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "location.hpp"

class MapObject {
    public:
        virtual void update() = 0;
        virtual void render() = 0;  
    protected:
        Location location; 
};

#endif
