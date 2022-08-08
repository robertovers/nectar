/*
Controller for updating or rendering to UI, the general status of MapObjects 
*/
#include "mapObjectController.hpp"

MapObjectController::MapObjectController(int *object_arr) { 
    objects = object_arr;
    // TODO: Complete constructor
};

void MapObjectController::updateObjects(void){
    for (int i=0; i<objects.size; i++) objects[i].update();
};

// Use still uncertain
void MapObjectController::addToObjects(MapObject object) { 
    // TODO: Add given object to objects - depends on resizable array implementation.
};

// Use still uncertain
void MapObjectController::rmvFromObjects(MapObject object) {
    // TODO: Remove given object from objects - depends on resizable array implementation.
};

// Maybe unneseccary - objects should be a simple byproduct of environment generation. (Depending on implementation)
void MapObjectController::loadObjects(Environment environment) {
    // Need to reference environment implementation.. - mayber better implemented in 
};

void MapObjectController::renderObjects(Environment environment) {
    // TODO
};
