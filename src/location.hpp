#ifndef location_hpp
#define location_hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include "templates.hpp"

class Agent;

class Location : public sf::Drawable {
    public:
        /**
         * @brief Construct a new Location object
         */
        Location();

        /**
         * @brief Construct a new Location object with a default colour
         *
         * @param x the x-coordinate of the location.
         * @param y the y-coordinate of the location.
         */
        Location(int x, int y);

        /**
         * @brief Construct a new Location object.
         * 
         * @param x the x-coordinate of the location.
         * @param y the y-coordinate of the location.
         * @param colour shared pointer to the Color that the location will be drawn with
         */
        Location(int x, int y, shared_ptr<sf::Color> colour);

        /**
         * @brief Checks if this location is a Plant - used before type casting.
         * 
         * @return true if this location is Plant.
         * @return false if this location is not a Plant.
         */
        virtual bool isPlant();
        void addAgent(Agent& a);
        void removeAgent(Agent& a);
        void clearAgents();
        int numAgents();
        int getX();
        int getY();
    protected:
        /**
         * @brief Renders this location to the target.
         * 
         * @param target a render target.
         * @param states states to be applied when rendering to the target.
         */
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        /// @brief This location's colour when drawn
        shared_ptr<sf::Color> colour;

        /// @brief This location's x-coordinate.
        int x;
        int y;
        std::vector<std::reference_wrapper<Agent>> agents;
        shared_ptr<sf::Shape> sprite = nullptr;
};

#endif