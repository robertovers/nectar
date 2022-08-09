#ifndef mapobjectcontroller_hpp
#define mapobjectcontroller_hpp

#include <SFML/Graphics.hpp>
#include "mapObject.hpp"
#include "environment.hpp"
#include <memory>
#include <vector>

class MapObjectController {
    public:
        MapObjectController() { };
        void updateObjects(void);
        void addToObjects(MapObject& object);
        void rmvFromObjects(MapObject& object);
        void loadObjects(Environment environment); // TBD
        void renderObjects();
    protected:
        std::vector<std::shared_ptr<MapObject>> objects;  //Temporary solution/Placeholder
};

#endif