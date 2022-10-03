#include <iostream>
#include <fstream>
#include "utility.hpp"

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
