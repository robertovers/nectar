
/**
 * @brief Top-level class that initiates and controls the simulation.
 *
 * The Application class is the top of the simulation heirarchy, and contains
 * the simulation loop that calls all update and render methods.
 */
class Application
{

public:
    /// @brief Construct a new Application object.
    Application();

    /// @brief Runs the simulation by initialising the simulation loop.
    int run();
};

/// @brief Enum for different status' of the simulation
enum Status
{

    // Simulation currently running
    Play,

    // Simulation currently paused
    Pause,

    // Simulation signalled to stop
    Stop,

    // Simulation currently stopped
    Stopped,

    // Report generated successfully
    ReportSuccess,

    // Report generation failed
    ReportFail
};

int Application::run()
{

    while (window.isOpen())
    {

        // Event handling loop
        while (window.pollEvent(event))
        {

            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                // Window closed by user
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                // Window resized by user
                simDisplay.updateViewport(event.size.width, event.size.height);
                ImGui::SFML::Update(window, deltaClock.restart());
                statsWindow.draw(event.size.width, event.size.height);
                ImGui::SFML::Render(window);
            }
        }

        // Clear display before rendering new components
        window.clear();

        ImGui::SFML::Update(window, deltaClock.restart());

        if (global_status == Status::Play)
        {

            // Update simulation metrics according to environment
            metrics->updateMetrics(*environment, clock.getElapsedTime());

            // Log metrics once per second
            cur_log = clock.getElapsedTime().asMilliseconds();
            if (cur_log - last_log > 1000)
            {
                metrics->toFile(DATA_OUT);
                last_log = cur_log;
            }

            // Update all agents
            agentController->updateAgents(*environment);
        }
        else if (global_status == Status::Stop)
        {
            // Begin generating report on new thread
            #ifdef _WIN32
                reportThread = std::thread(generate_report_windows, params);
            #elif __APPLE__
                reportThread = std::thread(generate_report_macos, params);
            #endif

            // Simulation now complete
            global_status = Status::Stopped;
        }

        // Draw UI windows
        statsWindow.draw();
        legendsWindow.draw();

        ImGui::SFML::Render(window);

        // Display main simulation window
        window.display();
    }

    // Wait for report generation thread
    if (reportThread.joinable())
    {
        reportThread.join();
    }

    ImGui::SFML::Shutdown();

    return EXIT_SUCCESS;
}