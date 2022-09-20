#include "InitialUI.hpp"

#define PARAMETERS 1
#define LINEHEIGHT 50
#define WINDOWWIDTH 800

InitialUI::InitialUI(){};

Parameters InitialUI::run(){
    std::cout << "Running initial UI Interface\n" ;
    Parameters parameters;
    
    //Window for setting simulation parameters - extra space for line for comfirm button (1) and instructions (3)
    sf::RenderWindow window(sf::VideoMode(500, 500), "Simulation Parameters");
    ImGui::SFML::Init(window);    

    sf::Clock deltaClock;
    while(window.isOpen()){
        ImGui::SFML::Update(window, deltaClock.restart());

        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type==sf::Event::Closed){
                parameters.exited=true;
                window.close();
            }
                
        }

        // Part of flags from imgui_demo.cpp
        static bool no_move = false;

        ImGuiWindowFlags window_flags = 0;
        if (no_move)        window_flags |= ImGuiWindowFlags_NoMove;


        ImGui::Begin("Simulation Parameters", NULL, window_flags);

        // Widgets
        //ImGui::ShowDemoWindow();
        static int dimensions[2]={parameters.columns,parameters.rows};

        ImGui::InputInt2("Grid Dimensions", &dimensions[0]);
        ImGui::InputInt("Scale", &parameters.scale);
        ImGui::InputInt("Bees", &parameters.bees);     
        ImGui::InputFloat("Soybean Probability", &parameters.soybean_p);        
   
        // Update parameter values
        parameters.rows = dimensions[1];
        parameters.columns = dimensions[0];

        // Close Parameter Selection screen
        static int ds_clicked=0;
        if(ImGui::Button("Display Simulation"))
            ds_clicked ++;
        if(ds_clicked) {
            std::cout << "Parameter Selection Complete" << std::endl;
            parameters.normal_exit = true;
            window.close();
        }

        ImGui::End();
        
        window.clear(sf::Color(127,127,127));
        
        ImGui::SFML::Render(window);
        window.display();
        
    }
    ImGui::SFML::Shutdown();
    return parameters;
    std::cout << "Finished running initial UI Interface\n" ;
    
}

