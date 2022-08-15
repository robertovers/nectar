#ifndef MAPOBJECTCONTROLLER_HPP
#define MAPOBJECTCONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include "mapObject.hpp"
#include "environment.hpp"
#include <memory>
#include <vector>


class MapObjectController {
    public:
        MapObjectController() { };
        void updateObjects();
        void addToObjects(std::shared_ptr<MapObject>& object);
        void rmvFromObjects(std::shared_ptr<MapObject>& object);
        void renderObjects();
    protected:
        std::vector<std::shared_ptr<MapObject>> objects;  //Temporary solution/Placeholder
};

#endif
