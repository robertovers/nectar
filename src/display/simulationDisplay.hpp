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
     * @param agentController The controller containing the agents in the simulation
     * @param environment The environment that on which the simulation is running
     */
    SimulationDisplay(shared_ptr<AgentController> agentController, shared_ptr<Environment> environment);
    sf::View getView() const { return view; }
    /**
     * @brief Updates the simulation's View to better fill the given window size whilst maintaining its aspect ratio
     * 
     * @param windowX The target window's width in pixels
     * @param windowY The target window's height in pixels
     */
    void updateViewport(float windowX, float windowY);
    /**
     * @brief Draw the simulation to the render target
     *
     * @param target Render target to draw to
     * @param states Current render states
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private: 
    ///  @brief the View that dictattets how the simulation should be drawn
    sf::View view = sf::View();
    ///  @brief The controller containing the agents in the simulation
    shared_ptr<AgentController> agentController;
    ///  @brief The environment that on which the simulation is running
    shared_ptr<Environment> environment;
};

#endif