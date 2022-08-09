#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "environment.hpp"
#include "mapGenerator.hpp"
#include "agentController.hpp"
#include "mapObjectController.hpp"

Application::Application() { }

void Application::run() { 

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Insect Simulations");

    BasicMapGenerator mapGenerator = BasicMapGenerator(0, 0, 0, 0, 0, 0, 0);
    AgentController agentController = AgentController();
    MapObjectController objectController = MapObjectController();
    
    Environment environment = mapGenerator.generateEnvironment(agentController, objectController);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        agentController.updateAgents(environment);
        agentController.renderAgents(window);

        objectController.updateObjects();
        objectController.renderObjects();

        window.display();
    }
}