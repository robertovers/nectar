#ifndef mapobject_hpp
#define mapobject_hpp

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
