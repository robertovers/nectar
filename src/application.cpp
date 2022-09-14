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
#include "imgui.h"
#include "imgui-SFML.h"
#include "application.hpp"
#include "environment.hpp"
#include "basicMapGenerator.hpp"
#include "agentController.hpp"
#include "utility.hpp"
#include "display/statsWindow.hpp"

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
    ImGui::SFML::Init(window);

    StatsWindow statsWindow = StatsWindow(metrics);
    simDisplay = SimulationDisplay(agentController, environment);
    updateDisplays(initialWindowWidth, initialWindowHeight);

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

        window.clear();

        agentController->updateAgents(*environment);

        window.setView(simDisplay.getView());
        simDisplay.draw(window, sf::RenderStates());

        statsWindow.display();

        ImGui::SFML::Render(window);

        window.display();

        //metrics->toConsole();
    }
    ImGui::SFML::Shutdown();
}

void Application::updateDisplays(int windowX, int windowY) {
    simDisplay.updateViewport(windowX, windowY);
}
