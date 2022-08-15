#ifndef MAPOBJECTCONTROLLER_CPP
#define MAPOBJECTCONTROLLER_CPP


/*
Controller for updating or rendering to UI, the general status of MapObjects 
*/
#include "mapObjectController.hpp"

void MapObjectController::updateObjects() {
    for (std::shared_ptr<MapObject> o : objects) {
        if (o != NULL) {
            o->update();
        }
    }
};


void MapObjectController::addToObjects(std::shared_ptr<MapObject>& object) { 
    // TODO: Add given object to objects - depends on resizable array implementation.
};


void MapObjectController::rmvFromObjects(std::shared_ptr<MapObject>& object) {
    // TODO: Remove given object from objects - depends on resizable array implementation.
};


void MapObjectController::renderObjects() {
    // TODO
};

#endif
