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


Parameters::Parameters() {
    rows=50;
    columns=50;
    scale=20;
    bees=50;
    soybean_p=.2;
    normal_exit=false;
};

#define WINDOWHEIGHT 196
#define WINDOWWIDTH 401

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

        ImGui::InputInt2("Grid Dimensions", &dimensions[0]);
        ImGui::InputInt("Scale", &parameters.scale);
        ImGui::InputInt("Bees", &parameters.bees);    
        ImGui::SliderFloat("Soybean Probability", &parameters.soybean_p, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_None);

        // Update parameter values
        parameters.rows = dimensions[0];
        parameters.columns = dimensions[1];

        // Display Simulation Widget
        static int ds_clicked=0;
        if(ImGui::Button("Display Simulation")) ds_clicked ++;
        if(ds_clicked) {
            parameters.normal_exit = true;
            window.close();
        }

         // Window size display
        ImVec2 size = ImGui::GetWindowSize();
        ImGui::SameLine();  ImGui::Text("Window size: [%2.fx%2.f]", size.x, size.y); 
        
        // Clear & Display/Render UI
        window.clear(sf::Color(255,234,155,100));
        ImGui::End();
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return parameters;    
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