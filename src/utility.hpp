#ifndef utility_hpp
#define utility_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include "environment.hpp"

struct Metrics {
    int days;
    int hours;
    int mins;
    int secs;
    float hive_nectar;
    float pollinated_count;

    void updateMetrics(Environment& env, sf::Time time);
    std::string timeString();
    void toConsole();
    void toFile(std::string filename);
    static void createDataFile(std::string filename);
};

struct ID {
    static int generateID() {
        static std::atomic<std::uint64_t> id { 0 };
        return id++;
    };
};

const std::string DATA_OUT = "sim_data.csv";

#endif