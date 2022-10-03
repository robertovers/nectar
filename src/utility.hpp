#ifndef utility_hpp
#define utility_hpp

#include <string>
#include <filesystem>
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


///@brief Parameters structure for storing simulation parameter values.
struct Parameters {

    ///@brief Number of rows for the simulation map. Note: Each grid on the map represents space required for a single crop
    int rows = 100;

    ///@brief Number of columns for the simulation map. Note: Each grid on the map represents space required for a single crop
    int columns = 100;

    ///@brief Scale of each grid on the simulation map. Note: Does not currently affect flight speed 
    int scale = 8;

    ///@brief Number of bees to use in the simulation.
    int bees = 50;

    ///@brief Probability of a soybean being planted in each grid from 0-1.
    float soybean_p = 0.1;

    /**
     * @brief  Number indicating the exit status of the simulation conguration display 
     * 
     * 0: Normal exit
     * 1: User exit
     * Otherwise: Error
     */
    int exit_status = 0;

    void check_limits();
};

/**
 * @brief simconfigUI function for a UI display for configuring simulation parameters.
 * 
 * The simcomfigUI functions creates a display with parameters and 
 * textboxes/sliders containing the default parameter values. These
 * textboxes/slides can then be altered by the user and finalised 
 * through clicking the display simulation button. 
 * 
 * @return Parameters structure of simulation parameter values to be used.
 */
Parameters simconfigUI();

void getWidgets(Parameters parameters, sf::RenderWindow* window, int* mapGeneratorSelectionStatus);
void getMapGeneratorWidgets(int* mapGeneratorSelectionStatus);
void getParameterWidgets(Parameters* parameters, sf::RenderWindow* window);

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

/// @brief Enum for different status' of the simulation
enum Status {

    // Simulation currently running
    Play,

    // Simulation currently paused
    Pause,

    // Simulation signalled to stop
    Stop,

    // Simulation currently stopped
    Stopped,

    // Report generated successfully
    ReportSuccess,

    // Report generation failed
    ReportFail
};

#endif