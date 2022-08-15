#ifndef MAPOBJECTCONTROLLER_HPP
#define MAPOBJECTCONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include "mapObject.hpp"
#include "environment.hpp"
#include <memory>
#include <vector>
#include "util.cpp"


class MapObjectController {
    public:
        MapObjectController() { };
        void updateObjects();
        void addToObjects(mapObjectPtr& object);
        int rmvFromObjects(mapObjectPtr object);
        void renderObjects();
    protected:
        mapObjectPtrVector objects;
};

#endif
