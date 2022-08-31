#ifndef rowmapgenerator_hpp
#define rowmapgenerator_hpp

#include "mapGenerator.hpp"
#include "honeybee.hpp"
#include "soybean.hpp"

// Generates an environment with soybeans and locations in alternate rows. Agents are randomly scattered
class RowMapGenerator : MapGenerator {
private:
	int envSizeX;
	int envSizeY;
	int beeCount;

public:
	/**
	* Settings for generated map
	*
	* @param envSizeX	 Length of the map
	* @param envSizeY	 Height of the map
	* @param beeCount	 Number of bees in the map
	*/
	RowMapGenerator(int envSizeX, int envSizeY, int beeCount);
	Environment generateEnvironment(AgentController& agentController);
};

#endif