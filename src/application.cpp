#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
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
    auto metrics = std::make_shared<Metrics>();

    sf::RenderWindow window(sf::VideoMode(initialWindowWidth, initialWindowHeight), "Insect Simulations");

    window.setFramerateLimit(30);

    // set up environment
    BasicMapGenerator mapGenerator = BasicMapGenerator(rows, columns, 50, 1);
    auto agentController = std::make_shared<AgentController>();
    auto environment = std::make_shared< Environment>(mapGenerator.generateEnvironment(*agentController));

    // set up display parts
    simDisplay = SimulationDisplay(agentController, environment);
    ImGui::SFML::Init(window);
    //statsDisplay = StatsBar(metrics);

    while (window.isOpen()) {

        sf::Event event;
        metrics->updateMetrics(*environment, clock.getElapsedTime());
        sf::Clock deltaClock;

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                updateDisplays(event.size.width, event.size.height);
             }
        }   

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();

        agentController->updateAgents(*environment);

        window.setView(simDisplay.getView());
        simDisplay.draw(window, sf::RenderStates());
        
        //window.setView(statsDisplay.getView());
        //statsDisplay.draw(window, sf::RenderStates());
        ImGui::SFML::Render(window);

        window.display();

        // freezes simulation when enabled
        //metrics.toConsole();
    }
    ImGui::SFML::Shutdown();
}

void Application::updateDisplays(int windowX, int windowY) {
    simDisplay.updateViewport(windowX, windowY);
    statsDisplay.updateViewport(windowX, windowY);
}
