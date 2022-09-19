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
    // need to keep aspect ratio of simulation
    float ratio = std::min(windowX / environment->getWidth(), windowY / environment->getHeight());
    float xWindowRatio = environment->getWidth()* ratio / windowX;
    float yWindowRatio = environment->getHeight () * ratio / windowY;

    // offset, to keep environment centred
    float xOffset = (windowX - environment->getWidth() * ratio) / (windowX * 2);
    sf::FloatRect simViewpont(xOffset, 0, xWindowRatio, yWindowRatio);
    view.setViewport(simViewpont);
}
 
void SimulationDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    environment->draw(target, states);
    agentController->draw(target, states);
}
