#include "initialDisplay.hpp"

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

/*
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
*/

#define PARAMETERS 1
#define LINEHEIGHT 50
#define WINDOWWIDTH 800

InitialDisplay::InitialDisplay(){};

void  InitialDisplay::start(){
    std::cout << "Running initial UI Interface\n" ;
    // Basic Simulation Params
    int tiles, bees;                        // params in use
    //enum mapGenerator, hiveLocation;
    // Advanced Simulation params
    //int sim_duration;                       // params not currently in use
    sf::Font font;     
    sf::String p1_input;
    sf::Text instructions, p1, p1_val, confirm;

    //Window for setting simulation parameters - extra space for line for comfirm button (1) and instructions (3)
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, (PARAMETERS+5)*LINEHEIGHT), "Simulation Parameters");
    ImGui::SFML::Init(window);    
    sf::Clock deltaClock;


    // Set Font
    if (!font.loadFromFile("../fonts/open-sans/OpenSans-Regular.ttf"))
    {
        std::cout << "Error loading font" << "../fonts/open-sans/OpenSans-Regular.ttf" << std::endl;
    }

    //Window use instructions
    // Start typing to enter parameter values
    // Implement later// Press enter or tab to go to next field  //Implement later(cursor should follow)
    // When confirm is highlighted press enter to start simulation
    instructions.setFont(font);
    instructions.setString("Instructions Placeholder\n.\n.\n");
    instructions.setPosition(WINDOWWIDTH/20 , LINEHEIGHT/2);

    p1.setFont(font);
    p1.setString("Tiles: ");
    p1.setPosition(WINDOWWIDTH/20, LINEHEIGHT*7/2);

    p1_val.setFont(font);
    p1_val.setPosition(WINDOWWIDTH/2, LINEHEIGHT*7/2);
    
    //text.setCharacterSize(10);
    //text.setFillColor(sf::Color::Green);

    while(window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type){
                //Closing Window
                case sf::Event::Closed:
                    window.close();
                // User Input
                case sf::Event::TextEntered:
                    if (event.text.unicode == 8) {                      // Backspace
                        p1_input += event.text.unicode; 
                        p1_val.setString(p1_input);
                    }
                    if (event.text.unicode < 128) {
                        p1_input += event.text.unicode; 
                        p1_val.setString(p1_input);
                    }
                    
            }
        }
        
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();
        
        window.clear(sf::Color(127,127,127));
        window.draw(instructions);
        window.draw(p1);
        window.draw(p1_val);
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    std::cout << "Finished running initial UI Interface\n" ;
}

