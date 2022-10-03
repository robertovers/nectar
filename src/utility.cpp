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

#define INT_LOWER_LIM 1
#define ROWS_UPPER_LIM 400
#define COLS_UPPER_LIM 400
#define SCALE_UPPER_LIM 50 
#define BEES_UPPER_LIM 10000

void Parameters::check_limits(){
    int int_lower_lim = 0;
    if (rows < INT_LOWER_LIM) rows = INT_LOWER_LIM;
    if (columns < INT_LOWER_LIM) columns = INT_LOWER_LIM;
    if (scale < INT_LOWER_LIM) scale = INT_LOWER_LIM;
    if (bees < INT_LOWER_LIM) bees = INT_LOWER_LIM;
    if (rows > ROWS_UPPER_LIM) rows = ROWS_UPPER_LIM;
    if (columns > COLS_UPPER_LIM) columns = COLS_UPPER_LIM;
    if (scale > SCALE_UPPER_LIM) scale = SCALE_UPPER_LIM;
    if (bees > BEES_UPPER_LIM) bees = BEES_UPPER_LIM;
}

#define WINDOWHEIGHT 196
#define WINDOWWIDTH 401

Parameters simconfigUI(){
    Parameters parameters;                              

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

        // Adds required widgets to window 
        static int mapSelectionStatus = 0;              // mapSelectionStatus = 0 represents incomplete Map Selection
        ImGui::Begin("Simulation Parameters", NULL, window_flags);
        switch (mapSelectionStatus) {
            case 0:
                getMapGeneratorWidgets(&mapSelectionStatus);
                break;
            case 1:
                getParameterWidgets(&parameters, &window);
                break;
            default:
                std::cout << "Invalid mapSelectionStatus value of %d.\n", mapSelectionStatus;
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

void getMapGeneratorWidgets(int* mapSelectionStatus){
    // Map Generator Combo Box
    const char* mapGenerators[] = { "Basic Map Generator", "Row Map Generator" };
    static int selected_generator_id = 0;
    const char* combo_preview_value = mapGenerators[selected_generator_id];  // The preview value visible before opening the combo
    if (ImGui::BeginCombo("Map Generator", combo_preview_value, 0)){
        for (int n = 0; n < IM_ARRAYSIZE(mapGenerators); n++){
            const bool is_selected = (selected_generator_id == n);

            if (ImGui::Selectable(mapGenerators[n], is_selected)) 
                selected_generator_id = n;

            if (is_selected)                    // Set the initial focus when opening the combo (scrolling + keyboard navigation focus) ## Source: imgui_demo.cpp
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }

    // Confirm Map Type Widget
    static int cmt_clicked=0;
    if(ImGui::Button("Confirm Map Type")) cmt_clicked ++;
    if(cmt_clicked)
        *mapSelectionStatus = 1;
};

void getParameterWidgets(Parameters* params, sf::RenderWindow* window){
    Parameters parameters = *params;
    static int dimensions[2]={parameters.columns,parameters.rows};

    // Parameter widgets
    ImGui::InputInt2("Grid Dimensions", &dimensions[0]);
    ImGui::InputInt("Scale", &parameters.scale);
    ImGui::InputInt("Bees", &parameters.bees);    
    ImGui::SliderFloat("Soybean Probability", &parameters.soybean_p, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_None);

    // Update parameter values
    parameters.rows = dimensions[0];
    parameters.columns = dimensions[1];
    parameters.check_limits();

    // Display Simulation Widget
    static int ds_clicked=0;
    if(ImGui::Button("Start Simulation")) {
        ds_clicked ++;
        std::cout << "Start Simulation Button Clicked, normal_exit = " << parameters.exit_status << std::endl ;
    }
    if(ds_clicked) {
        parameters.exit_status = 0;
        window->close();
    }

    // Window size display
    ImVec2 size = ImGui::GetWindowSize();
    ImGui::SameLine();  ImGui::Text("Window size: [%2.fx%2.f]", size.x, size.y); 
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
