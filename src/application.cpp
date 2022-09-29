/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file application.cpp
 * @brief Top-level class that initiates and controls the simulation.
 * @date 2022-09-10
 */

#include <SFML/Graphics.hpp>
#include <fstream>
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

    int rows = 100; int columns = 100; int initialWindowScale = 5;
    float initialWindowWidth = rows * initialWindowScale;
    float initialWindowHeight = columns * initialWindowScale;

    sf::Clock clock;
    auto metrics = std::make_shared<Metrics>();

    sf::RenderWindow window(sf::VideoMode(initialWindowWidth, initialWindowHeight), "Nectar");

    window.setFramerateLimit(30);

    // set up environment
    BasicMapGenerator mapGenerator = BasicMapGenerator(rows, columns, 1000, 20);
    auto agentController = std::make_shared<AgentController>();
    auto environment = std::make_shared<Environment>(mapGenerator.generateEnvironment(*agentController));
    environment->initLookupTable();

    // set up display parts
    ImGui::SFML::Init(window);

    StatsWindow statsWindow = StatsWindow(metrics);
    auto simDisplay = SimulationDisplay(agentController, environment);
    simDisplay.updateViewport(initialWindowWidth, initialWindowHeight);
    
    // metric logging
    Metrics::createDataFile(DATA_OUT);
    float cur_log, last_log = 0;

    while (window.isOpen()) {

        sf::Event event;
        sf::Clock deltaClock;

        metrics->updateMetrics(*environment, clock.getElapsedTime());

        cur_log = clock.getElapsedTime().asMilliseconds();
        if (cur_log - last_log > 1000) {
            metrics->toFile(DATA_OUT);
            last_log = cur_log;
        }

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                simDisplay.updateViewport(event.size.width, event.size.height);
             }
        }   

        ImGui::SFML::Update(window, deltaClock.restart());

        window.clear();

        agentController->updateAgents(*environment);

        window.setView(simDisplay.getView());
        simDisplay.draw(window, sf::RenderStates());

        statsWindow.draw();

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();
}
