#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#define PARAMETERS 1
#define LINEHEIGHT 50
#define WINDOWWIDTH 800

int main(){
    // Basic Simulation Params
    int tiles, bees;                        // params in use
    //enum mapGenerator, hiveLocation;
    // Advanced Simulation params
    //int sim_duration;                       // params not currently in use
    sf::String p1_input;
    sf::Text instructions, p1, confirm;

    //Window for setting simulation parameters - extra space for line for comfirm button (1) and instructions (3)
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, (PARAMETERS+5)*LINEHEIGHT), "Simulation Parameters");
    
    // Set Font
    sf::Font font;     
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
    
    //text.setCharacterSize(10);
    //text.setFillColor(sf::Color::Green);

    while(window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                case sf::Event::TextEntered:
                    std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
            }
        }
        window.clear(sf::Color(127,127,127));
        window.draw(instructions);
        window.draw(p1);

        window.display();
    }
}

