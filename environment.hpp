#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "location.hpp"

// Temporary Environment class
class Environment {
    public:
        int getSize() { return 0; };
    private:
        std::vector<Location> locations;
};

#endif