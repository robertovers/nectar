#include "simulationDisplay.hpp"

SimulationDisplay::SimulationDisplay(shared_ptr<AgentController> agentController, shared_ptr<Environment> environment) {
    this->agentController = agentController;
    this->environment = environment;
}

void SimulationDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    auto scaleTransform = spriteTransformation(1000, 1000);
    states.transform.combine(scaleTransform);
    environment->draw(target, states);
    agentController->draw(target, states);
}

sf::Transform SimulationDisplay::spriteTransformation(int windowWidth, int windowHeight) const {
    int rows = environment->getWidth();
    int columns = environment->getHeight();
    float rowWidth = static_cast<float>(windowWidth) / rows;
    float columnWidth = static_cast<float>(windowHeight) / columns;
    // use smallest width, to fit on screen/avoid distortion
    float displayWidth = rowWidth;
    if (rowWidth > columnWidth) {
        displayWidth = columnWidth;
    }
    return sf::Transform().scale(displayWidth, displayWidth);
}