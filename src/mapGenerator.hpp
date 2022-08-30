#ifndef mapgenerator_hpp
#define mapgenerator_hpp

#include "environment.hpp"
#include "agentController.hpp"

// Generates a populated map for the simulation to run on
class MapGenerator {
public:
	virtual Environment generateEnvironment(AgentController& agentController) = 0;
};

#endif