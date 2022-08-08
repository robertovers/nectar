#ifndef mapObjectController_hpp
#define mapObjectController_hpp

#include <SFML/Graphics.hpp>
// #include ... 

class MapObjectController {
    public:
        MapObjectController(int n){};
        updateObjects();
        addObjects(MapObject object);
        loadObjects(Environment environment);
        renderObjects();
    protected:
        MapObject[] objects;
};

#endif