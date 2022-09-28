#ifndef utility_hpp
#define utility_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include "environment.hpp"
#include "templates.hpp"

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
};

struct ID {
    static int generateID() {
        static std::atomic<std::uint64_t> id { 0 };
        return id++;
    };
};

/**
 * @brief Struct containing all colours used by different Locations in the simulation
 */
struct EnvColours {
    shared_ptr<sf::Color> soybeanColour;
    shared_ptr<sf::Color> nectarColour;
    shared_ptr<sf::Color> pollenColour;
    shared_ptr<sf::Color> hiveColour;
    shared_ptr<sf::Color> locationColour;

    /// @brief Create an EnvColours object, containing default colours
    EnvColours();
};

struct SoybeanOverlays {
    std::shared_ptr<sf::Shape> pollen;
    std::shared_ptr<sf::Shape> nectar;

    SoybeanOverlays();
};
#endif