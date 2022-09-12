#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "environment.hpp"
#include "basicMapGenerator.hpp"
#include "agentController.hpp"
#include "display/simulationDisplay.hpp"
#include "display/statsBar.hpp"
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

    // set up display parts
    SimulationDisplay simulationDisplay(std::make_shared<AgentController>(agentController), std::make_shared<Environment>(environment));
    StatsBar statisticsDisplay(std::make_shared<Metrics>(metrics));

    while (window.isOpen()) {

        sf::Event event;
        metrics.updateMetrics(environment, clock.getElapsedTime());

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                simulationDisplay.updateViewport(event.size.width, event.size.height);
                // TODO: update statistics bar?
             }
        }

        window.clear();

        agentController.updateAgents(environment);

        window.setView(simulationDisplay.getView());
        simulationDisplay.draw(window, sf::RenderStates());
        
        /*window.setView(statisticsDisplay.getView());
        statisticsDisplay.draw(window, sf::RenderStates());*/

        window.display();

        //metrics.toConsole();
    }
}

