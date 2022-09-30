#include <iostream>
#include <fstream>
#include "utility.hpp"

void Metrics::updateMetrics(Environment&env, sf::Time time) {
    int current_secs = time.asSeconds();
    int secs_elapsed = current_secs;
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
        << pollinated_count << ","
        << std::endl;

    out.close();
}

void Metrics::createDataFile(std::string filename) {
    std::fstream out;

    out.open(filename, std::ios::out | std::ios::trunc);
    
    out << "time"       << ","
        << "nectar"     << ","
        << "pollinated" << ","
        << std::endl;

    out.close();
};

void *generate_report_macos(void *arg) {
    std::filesystem::permissions(report_script_macos, std::filesystem::perms::owner_all);

    try {
        system(report_script_macos.string().c_str());
    } catch (const std::exception& e) {
        std::cout << "ERROR: Failed to generate report." << std::endl;
    }

    pthread_exit(NULL);
}

void *generate_report_windows(void *arg) {
    std::filesystem::permissions(report_script_windows, std::filesystem::perms::owner_all);

    try {
        system(report_script_windows.string().c_str());
    } catch (const std::exception& e) {
        std::cout << "ERROR: Failed to generate report." << std::endl;
    }

    pthread_exit(NULL);
}
