#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "environment.hpp"
#include "location.hpp"
#include "agentController.hpp"

Application::Application() { }

void Application::run() { 

    sf::Clock clock;
    float last_t = clock.getElapsedTime().asSeconds();
    float current_t;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Insect Simulations");
    window.setFramerateLimit(60);

    srand(time(NULL));

    // BasicMapGenerator mapGenerator = BasicMapGenerator(0, 0, 0, 0, 0, 0, 0);
    // AgentController agentController = AgentController(); 
    // Environment environment = mapGenerator.generateEnvironment(); 

    AgentController agentController = AgentController();
    Environment environment = Environment(50, 50);    
    agentController.addHoneyBees(environment);

    shared_ptr<Location> target_t = environment.getLocations()[rand() % 50][rand() % 50];
    for (auto a : agentController.getAgents()) {
        a->setTarget(target_t);
    }

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        current_t = clock.getElapsedTime().asSeconds();
        if (current_t - last_t > 5) {
            target_t = environment.getLocations()[rand() % 50][rand() % 50];
            for (auto a : agentController.getAgents()) {
                a->setTarget(target_t);
            }
            last_t = current_t;
        }

        for (auto row : environment.getLocations()) {
            for (auto loc : row) {
                if (loc->numAgents() > 0) {
                    loc->draw(window, sf::Color::Blue);
                }
            }
        }
        target_t->draw(window, sf::Color::Red);

        agentController.updateAgents(environment);
        agentController.drawAgents(window);
        
        window.display();
    }
}