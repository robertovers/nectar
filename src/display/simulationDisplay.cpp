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
    // TODO: not hardcode
    float adjustmentFactor = .9; // make room for bar

    float yWindowRatio = windowX / largestWindowSize;
    float xWindowRatio = windowY / largestWindowSize;

    sf::FloatRect simViewpont(0, 0, xWindowRatio, yWindowRatio * adjustmentFactor);
    view.setViewport(simViewpont);
}
 
void SimulationDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    environment->draw(target, states);
    agentController->draw(target, states);
}
