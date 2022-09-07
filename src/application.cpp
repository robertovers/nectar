#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "environment.hpp"
#include "basicMapGenerator.hpp"
#include "agentController.hpp"

Application::Application() { }

void Application::run() { 

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Insect Simulations");
    window.setFramerateLimit(30);

    BasicMapGenerator mapGenerator = BasicMapGenerator(50, 50, 50, 1);
    AgentController agentController = AgentController();
    
    Environment environment = mapGenerator.generateEnvironment(agentController);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                // update view to new window size
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear();

        agentController.updateAgents(environment);
        
        environment.draw(window);
        agentController.drawAgents(window);
        
        window.display();
    }
}