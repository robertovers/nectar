#ifndef mapObjectController_hpp
#define mapObjectController_hpp

#include <SFML/Graphics.hpp>
#include "mapObject.cpp"
#include "environment.cpp"
#include <memory>

class MapObjectController {
    public:
        MapObjectController(int *object_arr);
        void updateObjects(void);
        void addToObjects(MapObject object);
        void rmvFromObjects(MapObject object);
        void loadObjects(Environment environment);
        void renderObjects(void);
    protected:
        MapObject objects[];
};

#endif