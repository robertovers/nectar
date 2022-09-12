/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file application.hpp
 * @brief Application class that initiates and controls the simulation.
 * @date 2022-09-10
 */

#ifndef application_hpp
#define application_hpp

/**
 * @brief Application class that initiates and controls the simulation.
 * 
 * The Application class is the top of the simulation heirarchy, and contains
 * the simulation loop that calls all update and render methods.
 */
class Application {

    public:

        /**
         * @brief Construct a new Application object.
         */
        Application();

        /**
         * @brief Runs the simulation by initialising the simulation loop.
         */
        void run();

    private:

        /**
         * @brief Returns transformation that will be applied to all objects in the simulation.
         * 
         * @param rows the number of rows of location tiles.
         * @param columns the number of columns of location tiles.
         * @param windowWidth the width of the display window in pixels.
         * @param windowHeight the height of the display window in pixels.
         * @return sf::Transform 
         */
        sf::Transform spriteTransformation(int rows, int columns, int windowWidth, int windowHeight);
};

#endif