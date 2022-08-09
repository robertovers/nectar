#ifndef mapObjectController_hpp
#define mapObjectController_hpp

#include <SFML/Graphics.hpp>
#include "mapObject.cpp"
#include "environment.cpp"
#include <memory>
#include <vector>

class MapObjectController {
    public:
        MapObjectController(std::vector<std::shared_ptr<MapObject> >& objects_);
        void updateObjects(void);
        void addToObjects(MapObject& object);
        void rmvFromObjects(MapObject& object);
        void loadObjects(Environment environment); // TBD
        void renderObjects(void);
    protected:
        std::vector<std::shared_ptr<MapObject> > objects;
};

#endif