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

    void updateMetrics(Environment& env, sf::Time time);
    std::string timeString();
};

#endif