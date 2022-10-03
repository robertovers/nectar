#ifndef basicmapgenerator_hpp
#define basicmapgenerator_hpp

#include <algorithm>
#include <stdexcept>
#include "mapGenerator.hpp"
#include "environment.hpp"
#include "agentController.hpp"
#include "location.hpp"
#include "honeybee.hpp"
#include "soybean.hpp"

// Generates an environment with agents and objects randomly scattered around
class BasicMapGenerator : MapGenerator {
private:
	int envSizeX;
	int envSizeY;
	int beeCount;
	int cropChance;

public:
	/**
	* Settings for generated map
	*
	* @param envSizeX	 Length of the map
	* @param envSizeY	 Height of the map
	* @param beeCount	 Number of bees in the map
	* @param cropChance  Chance that a location will have a crop on it, out of 100.
	*					 For example, cropChance = 50 means 50/100 = 1/2 chance
	*/
	BasicMapGenerator(int envSizeX, int envSizeY, int beeCount, int cropChance);
	Environment generateEnvironment(AgentController& agentController);
};

#endif