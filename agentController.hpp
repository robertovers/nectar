#ifndef agentcontroller_hpp
#define agentcontroller_hpp

#include <vector>
#include "agent.hpp"

class AgentController {
    public:
        AgentController();
        void addAgent(Agent a);
    private:
        std::vector<Agent> agents;
};

#endif