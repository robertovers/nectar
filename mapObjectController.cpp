/*
Controller for calling updates or rendering to MapObjects.
Above functions, are called to all MapObjects that are referenced by a list of shared_ptr's - the mapObjectController attribute - "objects". 
*/
#include "mapObjectController.hpp"

//-- Non-member functions
void swap(auto& a, auto& b){ 
    auto temp = a;
    a = b;
    b = temp;
};

//-- Member functions 
void MapObjectController::updateObjects() {
    for (auto p : objects) if (p != nullptr) p->update();;
};

void MapObjectController::addToObjects(shared_ptr<MapObject>& object) { 
    objects.push_back(object);
};

void MapObjectController::renderObjects(sf::RenderWindow& window) {
    for (auto p : objects) if (p != nullptr) p->render(window);;
};

void MapObjectController::rmvFromObjects(shared_ptr<MapObject> object_ptr) {
    auto itr_lim = objects.end();;                                       // Auto can be replaced with shared_ptr_vector<MapObject>::iterator
    for (auto itr = objects.begin(); itr != itr_lim; ++itr) {
        if (*itr == object_ptr){
            itr_lim--;               // Decrementing it_lim to get iterator for last element in vector - Bad practice.. 
            swap(*itr, *itr_lim);
            objects.pop_back();
            break;
        } 
    }
};

