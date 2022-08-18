#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "environment.hpp"
#include "agentController.hpp"

Application::Application() { }

void Application::run() { 

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Insect Simulations");

    srand(time(NULL));

    // BasicMapGenerator mapGenerator = BasicMapGenerator(0, 0, 0, 0, 0, 0, 0);
    // AgentController agentController = AgentController(); 
    // Environment environment = mapGenerator.generateEnvironment(); 
    

    // -- BEGIN CODE FOR TESTING PURPOSES --

    AgentController agentController = AgentController();
    Environment environment = Environment(100, 100);    
    agentController.addHoneyBees(environment);

    // -- END OF TESTING CODE --


    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto a : agentController.getAgents()) {
            shared_ptr<Location> loc = a->getLocation(environment);
            loc->draw(window);
        }

        agentController.updateAgents(environment);
        agentController.drawAgents(window);
        
        window.display();
    }
}