/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file application.cpp
 * @brief Application class that initiates and controls the simulation.
 * @date 2022-09-10
 */

#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "environment.hpp"
#include "basicMapGenerator.hpp"
#include "agentController.hpp"
#include "utility.hpp"

Application::Application() { }

void Application::run() { 
    float initialWindowWidth = 1000;
    float initialWindowHeight = 1000;
    int rows = 50; int columns = 50;

    sf::Clock clock;
    Metrics metrics;

    sf::RenderWindow window(sf::VideoMode(initialWindowWidth, initialWindowHeight), "Insect Simulations");

    window.setFramerateLimit(30);

    // set up environment
    BasicMapGenerator mapGenerator = BasicMapGenerator(rows, columns, 50, 1);
    AgentController agentController = AgentController();
    Environment environment = mapGenerator.generateEnvironment(agentController);

    // set up view scale
    sf::Transform transformation = spriteTransformation(rows, columns, initialWindowWidth, initialWindowHeight);

    while (window.isOpen()) {

        sf::Event event;
        metrics.updateMetrics(environment, clock.getElapsedTime());

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                // update view to new window size
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                transformation = spriteTransformation(rows, columns, event.size.width, event.size.height);
            }
        }

        window.clear();

        agentController.updateAgents(environment);
        
        environment.draw(window, transformation);
        agentController.draw(window, transformation); 
        
        window.display();

        metrics.toConsole();
    }
}

sf::Transform Application::spriteTransformation(int rows, int columns, int windowWidth, int windowHeight){
    float rowWidth = static_cast<float>(windowWidth) / rows;
    float columnWidth = static_cast<float>(windowHeight) / columns;
    // use smallest width, to fit on screen/avoid distortion
    float displayWidth = rowWidth;
    if (rowWidth > columnWidth) {
        displayWidth = columnWidth;
    }
    return sf::Transform().scale(displayWidth, displayWidth);
}
