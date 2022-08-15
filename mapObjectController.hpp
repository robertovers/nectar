#ifndef MAPOBJECTCONTROLLER_HPP
#define MAPOBJECTCONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include "mapObject.hpp"
#include "environment.hpp"
#include <memory>
#include <vector>


template <typename T> using shared_ptr = std::shared_ptr<T>;
template <typename T> using shared_ptr_vector = std::vector<std::shared_ptr<T>>;


class MapObjectController {
    public:
        MapObjectController() { };
        void updateObjects();
        void addToObjects(shared_ptr<MapObject>& object);
        void rmvFromObjects(shared_ptr<MapObject> object);
        void renderObjects(sf::RenderWindow& window);
    protected:
        shared_ptr_vector<MapObject> objects;
};

#endif
