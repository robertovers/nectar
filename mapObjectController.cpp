/*
Controller for calling updates or rendering to MapObjects.
Above functions, are called to all MapObjects that are referenced by a list of shared_ptr's - the mapObjectController attribute - "objects". 
*/

#ifndef MAPOBJECTCONTROLLER_CPP
#define MAPOBJECTCONTROLLER_CPP

#include "mapObjectController.hpp"

//-- Non-member functions
void swap(shared_ptr<MapObject> &a, shared_ptr<MapObject> &b){
    shared_ptr<MapObject> temp = a;
    a = b;
    b = temp;
};

//-- Member functions 
void MapObjectController::updateObjects() {
    for (shared_ptr<MapObject> p : objects) if (p != nullptr) p->update();;
};

void MapObjectController::addToObjects(shared_ptr<MapObject>& object) { 
    objects.push_back(object);
};

void MapObjectController::rmvFromObjects(shared_ptr<MapObject> object_ptr) {
    auto it_lim = objects.end();                                                // shared_ptr_vector<MapObject>::iterator it_lim = objects.end();
    for (auto it = objects.begin(); it != it_lim; ++it) {
        if (*it == object_ptr){
            it_lim--;               // Decrementing it_lim to get iterator for last element in vector - Bad practice.. 
            swap(*it, *it_lim);
            objects.pop_back();
            break;
        } 
    }
};

void MapObjectController::renderObjects(sf::RenderWindow& window) {
    for (shared_ptr<MapObject> p : objects) if (p != nullptr) p->render(window);;
};

#endif
