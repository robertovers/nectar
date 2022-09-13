#ifndef simview_hpp
#define simview_hpp

#include "display.hpp"
#include "../templates.hpp"
#include "../agentController.hpp"
#include "../environment.hpp"

class SimulationDisplay : public Display {
public:
    SimulationDisplay();
    SimulationDisplay(shared_ptr<AgentController> agentController, shared_ptr<Environment> environment);
    void updateViewport(float windowX, float windowY);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    shared_ptr<AgentController> agentController;
    shared_ptr<Environment> environment;
};

#endif