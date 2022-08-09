class Environment{};
class Location{};
/*
Added in location attribute 'loc' as well as 'render' - may or may not be needed.  
*/

#ifndef mapObject_hpp
#define mapObject_hpp

#include <SFML/Graphics.hpp>
#include "location.cpp"

class MapObject {
    public:
        MapObject(Location location);
        virtual void update();
        virtual void render();  
    protected:
        Location location; 
};

#endif