#include "InitialUI.hpp"


#define PARAMETERS 1
#define LINEHEIGHT 50
#define WINDOWWIDTH 800

InitialUI::InitialUI(){};

Parameters InitialUI::run(){
    std::cout << "Running initial UI Interface\n" ;
    Parameters parameters;
    
    //Window for setting simulation parameters - extra space for line for comfirm button (1) and instructions (3)
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "Simulation Parameters");
    ImGui::SFML::Init(window);    

    sf::Clock deltaClock;
    while(window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            switch (event.type){
                //Closing Window
                case sf::Event::Closed:
                    window.close();
                // User Input
                default:
                    NULL;
            }
        }
        
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Simulation Parameters");
        ImGui::ShowDemoWindow();
        ImGui::InputInt("Resolution X", &parameters.sim_cols);
        ImGui::InputInt("Resolution Y", &parameters.sim_rows);        
        ImGui::InputInt("Bees", &parameters.bees);
        ImGui::End();
        
        window.clear(sf::Color(127,127,127));
        
        ImGui::SFML::Render(window);
        window.display();
        
    }
    ImGui::SFML::Shutdown();
    std::cout << "Finished running initial UI Interface\n" ;
    
}

