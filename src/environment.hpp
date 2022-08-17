#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Location;

// Temporary Environment class
class Environment {
    public:
        int getSize() { return 0; };
        std::vector<std::shared_ptr<Location>>& getLocations() { return locations; }
    private:
        std::vector<std::shared_ptr<Location>> locations;
};

#endif