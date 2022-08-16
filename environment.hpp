#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Location;

class Environment {
    private:
        int width;
        int height;
        std::vector<std::shared_ptr<Location>> locations;
    public:
        Environment(int width, int height);
        int getSize() { return 0; };
        std::vector<std::shared_ptr<Location>>& getLocations() { return locations; }
};

#endif