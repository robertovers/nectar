#ifndef simview_hpp
#define simview_hpp

#include <SFML/Graphics.hpp>
#include "../templates.hpp"
#include "../agentController.hpp"
#include "../environment.hpp"

class SimulationDisplay : sf::Drawable {
public:
    SimulationDisplay(shared_ptr<AgentController> agentController, shared_ptr<Environment> environment);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    // Returns transformation that will be applied to all objects in the simulation
    sf::Transform spriteTransformation(int windowWidth, int windowHeight) const;
    shared_ptr<AgentController> agentController;
    shared_ptr<Environment> environment;
};

#endif