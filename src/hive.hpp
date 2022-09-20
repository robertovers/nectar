/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file hive.hpp
 * @brief A class to represent the Honeybees' hive.
 * @date 2022-09-19
 */

#ifndef hive_hpp
#define hive_hpp

#include <SFML/Graphics.hpp>
#include "location.hpp"

/**
 * @brief A class to represent the Honeybees' hive.
 * 
 * The Hive extends the Location class, and is a simple abstraction of a hive
 * that the honeybees return to for depositing their nectar.
 */
class Hive : public Location {

    public:

        /**
         * @brief Construct a new Hive object.
         */
        Hive() : Hive(0, 0) { };

        /**
         * @brief Construct a new Hive object.
         * 
         * @param x the x-coordinate for the hive.
         * @param y the y-coordinate for the hive.
         */
        Hive(int x, int y);

        /**
         * @brief Checks if this location is a Plant.
         * 
         * @return false 
         */
        bool isPlant() override;

        /**
         * @brief Adds an a float amount of nectar to the hive.
         * 
         * @param amount the amount of nectar to deposit.
         */
        void depositNectar(float amount);

        /**
         * @brief Get the total amount of nectar in the hive. 
         * 
         * @return a float - the total amount of nectar.
         */
        float getNectar();

    private:

        /// @brief The total amount of nectar in the hive.
        float nectar = 0;
};

#endif