#ifndef hive_hpp
#define hive_hpp

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Hive : public Location {
    public:

        /**
         * @brief Construct a new Hive object.
         */
        // Hive() : Hive(0, 0) { };

        /**
         * @brief Construct a new Hive object.
         * 
         * @param x the x-coordinate for the hive.
         * @param y the y-coordinate for the hive.
         */
        Hive(int x, int y, shared_ptr<sf::Color> colour) : Location(x, y, colour) {};

        /**
         * @brief Checks if this location is a Plant.
         * 
         * @return false 
         */
        bool isPlant() override;
        void depositNectar(float amount);
        float getNectar();
    private:
        float nectar = 0;
};

#endif