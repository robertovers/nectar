#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include "location.hpp"
#include "templates.hpp"

class Environment {
    public:
        Environment();
        Environment(int w, int h);
        vector2D_shared_ptr<Location>& getLocations();
        int getSize();
        int getWidth();
        int getHeight();
    private:
        int width;
        int height;
        vector2D_shared_ptr<Location> locations;
};

#endif