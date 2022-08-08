/*
Added in location attribute 'loc' - may or may not be needed.  
*/

#ifndef mapObject_hpp
#define mapObject_hpp

#include 

class MapObject {
    public:
        virtual MapObject();
        virtual void update(){};
    protected:
        Location loc; 
}

#endif