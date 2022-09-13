#ifndef application_hpp
#define application_hpp

#include "display/simulationDisplay.hpp"
#include "display/statsBar.hpp"

class Application {
    public:
        Application();
        void run();
        void updateDisplays(int windowX, int windowY);
    private:
        SimulationDisplay simDisplay;
        StatsBar statsDisplay;
};

#endif