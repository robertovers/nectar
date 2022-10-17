/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file utility.cpp
 * @brief File containing utility functions used throughout the project. 
 * @date 2022-10-04
 */

#include <iostream>
#include <fstream>
#include "utility.hpp"
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

void Metrics::updateMetrics(Environment&env, sf::Time time) {
    secs_elapsed = time.asSeconds();
    days = secs_elapsed / 86400;
    hours = (secs_elapsed / 3600) % 24;
    mins = (secs_elapsed / 60) % 60;
    secs = secs_elapsed % 60;
    hive_nectar = env.getHive()->getNectar();
    pollinated_count = env.getPollinatedCount();
}

std::string Metrics::timeString() {
    std::string res = std::to_string(days)  + "d : " +
                      std::to_string(hours) + "h : " +
                      std::to_string(mins)  + "m : " +
                      std::to_string(secs)  + "s";
    return res;
}

void Metrics::toConsole() {
    std::string s = "Simulation running for " + timeString() + 
                    " , Nectar in Hive: " + std::to_string(hive_nectar) + 
                    ", Flowers Pollinated: " + std::to_string(pollinated_count);
    std::cout << s;

    for (int i=0; i<s.length(); i++) {
        std::cout << "\b";
    }

    std::cout << std::flush;
}


void Metrics::toFile(std::string filename) {
    std::ofstream out;

    out.open(filename, std::ios::out | std::ios::app);

    out << secs_elapsed     << ","
        << hive_nectar      << ","
        << pollinated_count 
        << std::endl;

    out.close();
}

void Metrics::createDataFile(std::string filename) {
    std::fstream out;

    out.open(filename, std::ios::out | std::ios::trunc);
    
    out << "time"       << ","
        << "nectar"     << ","
        << "pollinated"
        << std::endl;

    out.close();
};

#define DIMS_MAX 400
#define SCALE_MAX 50 
#define BEES_MAX 10000

/**
 * @brief A function for restricting patameter elements to realistic/optimal values.
 * Limits were defined according to simulation perfornace limits and basic reason such as having dimensions > 0. 
 * 
 */
void Parameters::check_limits(){
    if (rows < 1) rows = 1;
    if (rows > DIMS_MAX) rows = DIMS_MAX;

    if (columns < 1) columns = 1;
    if (columns > DIMS_MAX) columns = DIMS_MAX;

    if (scale < 1) scale = 1;
    if (scale > SCALE_MAX) scale = SCALE_MAX;

    if (bees < 0) bees = 0;
    if (bees > BEES_MAX) bees = BEES_MAX;

    if (soybean_p < 0) soybean_p = 0.05;
    if (soybean_p > 1) soybean_p = 1;
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

EnvColours::EnvColours() {
    soybeanColour = std::make_shared<sf::Color>(0, 50, 35);  // dark green
    nectarColour = std::make_shared<sf::Color>(187, 205, 17);  // light soybean-colour green
    pollenColour = std::make_shared<sf::Color>(247, 215, 90);   // yellow
    hiveColour = std::make_shared<sf::Color>(255, 0, 0);  // bright red
    locationColour = std::make_shared<sf::Color>(104, 78, 59);  // brown
}

SoybeanOverlays::SoybeanOverlays() {
    nectar = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>(sf::Vector2f(1,1)));
    pollen = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>(sf::Vector2f(1,1)));
}