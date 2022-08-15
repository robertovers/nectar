/*
Controller for updating or rendering to UI, the general status of MapObjects 
*/
#ifndef MAPOBJECTCONTROLLER_CPP
#define MAPOBJECTCONTROLLER_CPP

#include "mapObjectController.hpp"

/// Util Functions
void swap_itr(mapObjectPtrVector::iterator a, mapObjectPtrVector::iterator b){
    mapObjectPtr temp;
    temp = *a;
    *a = *b;
    *b = temp;
};
///

void MapObjectController::updateObjects() {
    for (mapObjectPtr p : objects) if (p != nullptr) p->update();;
};

void MapObjectController::addToObjects(mapObjectPtr& object) { 
    objects.push_back(object);
};

/*
Attempts to remove a given mapObject shared_pointer 'object_ptr" from the list of mapObjects pointers 'objects' owned by the mapObjectController.
Returns error int 1 if mapObject is not found, and 0 is object is found and succesfully removed.
*/
int MapObjectController::rmvFromObjects(mapObjectPtr object_ptr) {
    mapObjectPtr temp = nullptr;
    mapObjectPtrVector::iterator it_lim = objects.end();

    for (mapObjectPtrVector::iterator it = objects.begin(); it != it_lim; ++it) {
        if (*it == object_ptr){
            it_lim--;               // Decrementing it_lim to get iterator for last element in vector - Bad practice.. 
            swap_itr(it, it_lim);
            objects.pop_back();
            break;
        } 
    }

    if (temp == nullptr) return 1;
    else return 0;
};

void MapObjectController::renderObjects() {
    // TODO
};

#endif
