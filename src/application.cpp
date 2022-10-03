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
#include <iostream>
#include <thread>
#include "application.hpp"

const std::string DATA_OUT = "reporting/sim_data.csv";
const std::filesystem::path report_script_macos = "reporting/generate_macos.sh";
const std::filesystem::path report_script_windows = "reporting\\generate_windows.bat";

Status global_status = Status::Play;

Application::Application() { }

int Application::run() {
    // Acquire simulation parameters via initial user interface
    Parameters params = simconfigUI();     

    // Attempt at making program conclude early if initial UI is not closed via load simulation button. But not working...
    if (!params.normal_exit) {
        std::cout << "Program exited by user\n";
        exit(1);
    }

    // initial simulation settings
    auto envColours = EnvColours();  // default colours
    auto soybeanOverlays = SoybeanOverlays();
    float initialWindowWidth = params.rows * params.scale;
    float initialWindowHeight = params.columns * params.scale;

    sf::Clock clock;
    auto metrics = std::make_shared<Metrics>();

    // set up window
    sf::RenderWindow window(sf::VideoMode(initialWindowWidth, initialWindowHeight), "Nectar");
    sf::Image icon;
    if (icon.loadFromFile("bee_hex.png")) {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    };
    
    window.setFramerateLimit(30);

    // set up environment
    BasicMapGenerator mapGenerator = BasicMapGenerator(envColours, soybeanOverlays, params.rows, params.columns, params.bees, params.soybean_p*100);
    auto agentController = std::make_shared<AgentController>();
    auto environment = std::make_shared<Environment>(mapGenerator.generateEnvironment(*agentController));
    environment->initLookupTable();

    // set up display parts
    ImGui::SFML::Init(window);

    StatsWindow statsWindow = StatsWindow(metrics);
    auto legendsWindow = LegendsWindow(envColours, soybeanOverlays);
    auto simDisplay = SimulationDisplay(agentController, environment);
    simDisplay.updateViewport(initialWindowWidth, initialWindowHeight);
    
    // metric logging
    Metrics::createDataFile(DATA_OUT);
    float cur_log, last_log = 0;

    // multithreading for report generation
    std::thread reportThread;

    while (window.isOpen()) {

        sf::Event event;
        sf::Clock deltaClock;

        // event loop
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();

            } else if (event.type == sf::Event::Resized) {
                simDisplay.updateViewport(event.size.width, event.size.height);

                ImGui::SFML::Update(window, deltaClock.restart());
                statsWindow.draw(event.size.width, event.size.height);
                ImGui::SFML::Render(window);
            }
        }

        window.clear();

        ImGui::SFML::Update(window, deltaClock.restart());

        // status updates
        if (global_status == Status::Play || global_status == Status::Pause) {
            global_status = legendsWindow.getStatus();
        } else if (global_status == Status::ReportSuccess || global_status == Status::ReportFail) {
            legendsWindow.setStatus(global_status);
        }

        if (global_status == Status::Play) {

            metrics->updateMetrics(*environment, clock.getElapsedTime());
    
            cur_log = clock.getElapsedTime().asMilliseconds();
            if (cur_log - last_log > 1000) {
                metrics->toFile(DATA_OUT);
                last_log = cur_log;
            }
    
            agentController->updateAgents(*environment);

        } else if (global_status == Status::Stop) {

            // begin generating report on new thread
            #ifdef _WIN32
                reportThread = std::thread(generate_report_windows);
            #elif __APPLE__
                reportThread = std::thread(generate_report_macos);
            #endif

            global_status = Status::Stopped;
        }

        window.setView(simDisplay.getView());
        simDisplay.draw(window, sf::RenderStates());

        statsWindow.draw();
        legendsWindow.draw();

        ImGui::SFML::Render(window);

        window.display();
    }

    if (reportThread.joinable()) {
        reportThread.join();
    }

    ImGui::SFML::Shutdown();

    return EXIT_SUCCESS;
}

void generate_report_macos() {
    std::filesystem::permissions(report_script_macos, std::filesystem::perms::owner_all);

    try {
        system(report_script_macos.string().c_str());
    } catch (const std::exception& e) {
        global_status = Status::ReportFail;
    }

    global_status = Status::ReportSuccess;
}

void generate_report_windows() {
    std::filesystem::permissions(report_script_windows, std::filesystem::perms::owner_all);

    try {
        system(report_script_windows.string().c_str());
    } catch (const std::exception& e) {
        global_status = Status::ReportFail;
    }

    global_status = Status::ReportSuccess;
}
