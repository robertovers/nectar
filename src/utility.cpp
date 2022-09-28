#include <iostream>
#include "utility.hpp"

void Metrics::updateMetrics(Environment&env, sf::Time time) {
    int current_secs = time.asSeconds();
    days = current_secs / 86400;
    hours = (current_secs / 3600) % 24;
    mins = (current_secs / 60) % 60;
    secs = current_secs % 60;
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

EnvColours::EnvColours() {
    soybeanColour = std::make_shared<sf::Color>(0, 50, 35);
    nectarColour = std::make_shared<sf::Color>(187, 205, 17);
    pollenColour = std::make_shared<sf::Color>(247, 215, 90);
    hiveColour = std::make_shared<sf::Color>(255, 0, 0);
    locationColour = std::make_shared<sf::Color>(104, 78, 59);
}

SoybeanOverlays::SoybeanOverlays() {
    nectar = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>(sf::Vector2f(1,1)));
    pollen = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>(sf::Vector2f(1, 1)));

    
}
