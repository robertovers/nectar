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
#include <imgui.h>
#include <imgui-SFML.h>
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

    // Program concludes early if initial UI is not closed via load simulation button
    if (params.exit_status) {
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
    MapGenerator* mapGenerator;
    switch (params.selectedGenerator) {
        case 0:
            mapGenerator = new BasicMapGenerator(envColours, soybeanOverlays, params.rows, params.columns, params.bees, params.soybean_p*100);
            break;
        case 1:
            mapGenerator = new RowMapGenerator(envColours, soybeanOverlays, params.rows, params.columns, params.bees);
            break;
        default:
            break;
    }
    auto agentController = std::make_shared<AgentController>();
    auto environment = std::make_shared<Environment>(mapGenerator->generateEnvironment(*agentController));
    environment->initLookupTable();
    delete mapGenerator;

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
                reportThread = std::thread(generate_report_windows, params);
            #elif __APPLE__
                reportThread = std::thread(generate_report_macos, params);
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

void generate_report_macos(Parameters params) {
    std::filesystem::permissions(report_script_macos, std::filesystem::perms::owner_all);

    try {
        system((
            report_script_macos.string() 
            + " " + std::to_string(params.bees)
            + " " + std::to_string(params.rows)
            + " " + std::to_string(params.columns)
            + " " + std::to_string(params.soybean_p)
        ).c_str());
    } catch (const std::exception& e) {
        global_status = Status::ReportFail;
    }

    global_status = Status::ReportSuccess;
}

void generate_report_windows(Parameters params) {
    std::filesystem::permissions(report_script_windows, std::filesystem::perms::owner_all);

    try {
        system((
            report_script_windows.string() 
            + " " + std::to_string(params.bees)
            + " " + std::to_string(params.rows)
            + " " + std::to_string(params.columns)
            + " " + std::to_string(params.soybean_p)
        ).c_str());
    } catch (const std::exception& e) {
        global_status = Status::ReportFail;
    }

    global_status = Status::ReportSuccess;
}


#define WINDOWHEIGHT 196
#define WINDOWWIDTH 401

/**
 * @brief Function running a fixed window for seleting initial simulation parameters
 * 
 * @return A Parameters structure with attributes representing user-defined values of different simulation parameters 
 */
Parameters simconfigUI(){
    Parameters parameters;                              
    static int dimensions[2]={parameters.columns,parameters.rows};

    //SFMl & Imgui Window Initialization
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Simulation Parameters", sf::Style::Titlebar);
    ImGui::SFML::Init(window);    

    sf::Clock deltaClock;

    while(window.isOpen()){
        ImGui::SFML::Update(window, deltaClock.restart());

        // Handling SFML Window Events
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type==sf::Event::Closed) window.close();
        }

        // ImGui Window Configurations
        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
        
        // ImGui window position setting incase of missing default 
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 20, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);

        // Adding widgets to window
        ImGui::Begin("Simulation Parameters", NULL, window_flags);

        static int mapGeneratorConfirmed = 0;              // map generator initially not confirmed
        if (!mapGeneratorConfirmed)                                         // Map generation widgets
        {                             
            getMapGeneratorWidgets(&parameters, &mapGeneratorConfirmed);    
        }
        else                                                                // Parameter selection widgets
        {
            getDefaultParameterWidgets(&parameters);            // Default Parameter widgets    

            // Additional Parameter widgets
            switch (parameters.selectedGenerator) {             
                case 0:
                    ImGui::SliderFloat("Soybean Probability", &parameters.soybean_p, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_None);
                    break;
                case 1:
                    break;
                default:
                    break;
            }

            // "Display Simulation" Widget Button
            static int ds_clicked=0;
            if(ImGui::Button("Start Simulation")) {
                ds_clicked ++;
            }
            if(ds_clicked) {
                parameters.exit_status = 0;
                window.close();
            }
            /* Present for debugging/referenceing purposes
            // Window size display
            ImVec2 size = ImGui::GetWindowSize();
            ImGui::SameLine();  ImGui::Text("Window size: [%2.fx%2.f]", size.x, size.y); */
        }
        
        // Clear & Display/Render UI
        window.clear(sf::Color(255,234,155,100));
        ImGui::End();
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return parameters;    
};

/**
 * @brief Sub-function exclusively for simconfigUI function for clarity of code. Not to be used elsewhere.
 *  Adds ImGUI widgets for the initial simulation map selection
 * 
 * @param parameters 
 * @param mapGeneratorConfirmed 
 */
void getMapGeneratorWidgets(Parameters* parameters, int* mapGeneratorConfirmed){
    // Map Generator Combo Box Setup
    const char* mapGenerators[] = { "Basic Map Generator", "Row Map Generator" };   // Must be in a specific order
    static int selected_generator_id = 0;
    const char* combo_preview_value = mapGenerators[selected_generator_id];  // The preview value visible before opening the combo
    
    // Map Generator Combo Box 
    if (ImGui::BeginCombo("Map Generator", combo_preview_value, 0)){
        for (int n = 0; n < IM_ARRAYSIZE(mapGenerators); n++){
            const bool is_selected = (selected_generator_id == n);
            if (ImGui::Selectable(mapGenerators[n], is_selected))   selected_generator_id = n;
            if (is_selected) ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }

    // Confirm Map Type Widget
    static int cmt_clicked=0;
    if(ImGui::Button("Confirm Map Type")) cmt_clicked ++;
    if(cmt_clicked) {
        *mapGeneratorConfirmed = 1;
        parameters->selectedGenerator = selected_generator_id;
    }
};

/**
 * @brief Sub-function exclusively for simconfigUI function for clarity of code. Not to be used elsewhere.
 *  Adds the ImGUI widgets for default simulation parameters - parameters required for all environment maps.
 * 
 * @param parameters A structure for storing initial simulation parameters according to user input
 */
void getDefaultParameterWidgets(Parameters* parameters) {
    static int dimensions[2]={parameters->columns,parameters->rows};

    // Default Parameter widgets
    ImGui::InputInt2("Grid Dimensions", &dimensions[0]);
    ImGui::InputInt("Scale", &parameters->scale);
    ImGui::InputInt("Bees", &parameters->bees);    

    // Update parameter values
    parameters->rows = dimensions[0];
    parameters->columns = dimensions[1];
    parameters->check_limits();
}
