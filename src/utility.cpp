#include "utility.hpp"

void Metrics::updateMetrics(Environment&env, sf::Time time) {
    int current_secs = time.asSeconds();
    days = current_secs / 86400;
    hours = current_secs / 3600;
    mins = current_secs / 60;
    secs = current_secs % 60;
}

std::string Metrics::timeString() {
    std::string res = std::to_string(days)  + "d : " +
                      std::to_string(hours) + "h : " +
                      std::to_string(mins)  + "m : " +
                      std::to_string(secs)  + "s";
    return res;
}