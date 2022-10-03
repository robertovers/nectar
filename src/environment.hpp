#ifndef environment_hpp
#define environment_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include "location.hpp"
#include "hive.hpp"
#include "templates.hpp"

class Environment {
    public:
        /**
         * @brief Construct a new Environment object.
         * 
         * @param w width in tiles
         * @param h height in tiles
         */
        Environment(int w, int h, shared_ptr<sf::Color> locColour);

        /**
         * @brief Renders the environment to the target.
         * 
         * @param target a reference to a render target.
         * @param states states to be applied when rendering to the target.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states);
        void setHive(shared_ptr<Hive> h);
        int getSize() const;
        int getWidth() const;
        int getHeight() const;
        // manually iterates through locations to count agents.
        int agentCount();
        // manually iterate through locations, counting plants
        int plantCount(); 
        void changeLocation(int x, int y, shared_ptr<Location> newLocation);
        void incPollinatedCount();
        int getPollinatedCount();
    private:
        int width;
        int height;
        vector2D_shared_ptr<Location> locations;
        shared_ptr<Hive> hive;
        int pollinated_count = 0;
};

#endif