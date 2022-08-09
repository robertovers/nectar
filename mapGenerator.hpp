#ifndef mapgenerator_hpp
#define mapgenerator_hpp

#include "environment.hpp"

// Generates a populated map for the simulation to run on
class MapGenerator {
public:
	virtual Environment generateEnvironment() = 0;
};

// Generates an environment with agents and objects randomly scattered around
class BasicMapGenerator : MapGenerator {
private:
	int envSizeX;
	int envSizeY;
	int beeCount;
	int waspCount;
	int flowerCount;
	int cropCount;
	int caterpillarCount;

public:
	BasicMapGenerator(int envSizeX, int envSizeY, int beeCount, int waspCount, int flowerCount, int cropCount, int caterpillarCount);
	Environment generateEnvironment();
	int totalPlants();
	int totalAgents();
};
#endif