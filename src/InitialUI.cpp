#include "InitialUI.hpp"

#define WINDOWHEIGHT 300
#define WINDOWWIDTH 400

InitialUI::InitialUI(){};

Parameters InitialUI::run(){
    std::cout << "Running initial UI Interface\n" ;
    Parameters parameters;
    static int dimensions[2]={parameters.columns,parameters.rows};

    //Window for setting simulation parameters - extra space for line for comfirm button (1) and instructions (3)
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Simulation Parameters");
    ImGui::SFML::Init(window);    

    sf::Clock deltaClock;
    while(window.isOpen()){
        ImGui::SFML::Update(window, deltaClock.restart());

        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type==sf::Event::Closed){
                parameters.normal_exit=true;
                window.close();
            }

            if (event.type == sf::Event::Resized){
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
        }
    
        //Initializing ImGui window
        static bool no_move = false;
        ImGuiWindowFlags window_flags = 0;
        if (no_move)        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_AlwaysAutoResize;

        // Adding widgets to window
        ImGui::Begin("Simulation Parameters", NULL, window_flags);
        ImGui::InputInt2("Grid Dimensions", &dimensions[0]);
        ImGui::InputInt("Scale", &parameters.scale);
        ImGui::InputInt("Bees", &parameters.bees);    
        ImGui::SliderFloat("Soybean Probability", &parameters.soybean_p, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_None);
   
        // Update parameter values
        parameters.rows = dimensions[0];
        parameters.columns = dimensions[1];

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
        
        window.clear(sf::Color(255,234,155,100));
        
        ImGui::SFML::Render(window);
        window.display();
        
    }
    ImGui::SFML::Shutdown();
    return parameters;
    std::cout << "Finished running initial UI Interface\n" ;
    
}

