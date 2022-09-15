/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file simulationDisplay.hpp
 * @brief View controlling the display of the running simulation.
 * @date 2022-09-14
 */

#ifndef simview_hpp
#define simview_hpp

#include <SFML/Graphics.hpp>
#include "../templates.hpp"
#include "../agentController.hpp"
#include "../environment.hpp"

/**
 * @brief Class managing the display of the simulation.
 * 
 * It manages the simulation's View (which attempts to fill the window whilst maintaining its aspect ratio)
 * and drawing the entire simulation to a render target.
 */
class SimulationDisplay {
public:
    /**
     * @brief Construct a new simulation display 
     * 
     * @param agentController the controller containing the agents in the simulation
     * @param environment thee environment that on which the simulation is running
     */
    SimulationDisplay(shared_ptr<AgentController> agentController, shared_ptr<Environment> environment);
    sf::View getView() const { return view; }
    /**
     * @brief Updates the simulation's View to better fill the given window size whilst maintaining its aspect ratio
     * 
     * @param 
     */
    void updateViewport(float windowX, float windowY);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private: 
    sf::View view = sf::View();
    shared_ptr<AgentController> agentController;
    shared_ptr<Environment> environment;
};

#endif