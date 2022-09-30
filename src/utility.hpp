#ifndef utility_hpp
#define utility_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include <filesystem>
#include <pthread.h>
#include "environment.hpp"
#include "templates.hpp"

struct Metrics {
    int days;
    int hours;
    int mins;
    int secs;
    int secs_elapsed;
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

/// @brief Struct containing pointers to the overlays to used by Soybeans
struct SoybeanOverlays {
    /// @brief Overlay used when displaying pollen data
    std::shared_ptr<sf::Shape> pollen;
    /// @brief Overlay used when displaying nectar data
    std::shared_ptr<sf::Shape> nectar;

    /// @brief Create a SoybeanOverlays object, containing default, full-location-sized overlays
    SoybeanOverlays();
};

#endif