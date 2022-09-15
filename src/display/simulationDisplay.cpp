/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file simulationDisplay.cpp
 * @brief View controlling the display of the running simulation.
 * @date 2022-09-14
 */

#include "simulationDisplay.hpp"

SimulationDisplay::SimulationDisplay(shared_ptr<AgentController> agentController, shared_ptr<Environment> environment) {
    this->agentController = agentController;
    this->environment = environment;
    // set view to cover entire environment
    view.reset(sf::FloatRect(0, 0, environment->getWidth(), environment->getHeight()));
}
    
void SimulationDisplay::updateViewport(float windowX, float windowY) {
    // need to keep square aspect ratio for simulation
    float largestWindowSize = windowX;
    if (windowY > windowX) {
        largestWindowSize = windowY;
    }
    float yWindowRatio = windowX / largestWindowSize;
    float xWindowRatio = windowY / largestWindowSize;

    // offset, to keep environment centred
    float xOffset = (windowX - windowX * xWindowRatio) / (largestWindowSize * 2);
    sf::FloatRect simViewpont(xOffset, 0, xWindowRatio, yWindowRatio);
    view.setViewport(simViewpont);
}
 
void SimulationDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    environment->draw(target, states);
    agentController->draw(target, states);
}
