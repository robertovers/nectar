/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file basicMapGenerator.hpp
 * @brief MapGenerator for generating an Environment with Honeybees and Soybeans randomly scattered around
 * @date 2022-09-28
 */
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
#include "utility.hpp"

/**
 * @brief MapGenerator that generates an Environment with Honeybees and Soybeans randomly scattered around
 */
class BasicMapGenerator : public MapGenerator {
	
	public:
		/**
		* @brief Create a new BasicMapGenerator with settings for generated map
		*
		* @param envColours  Colours to be used by the locations in map
		* @param soybeanOverlays Pointers to the overlays to be used by Soybeans
		* @param envSizeX	 Length of the map
		* @param envSizeY	 Height of the map
		* @param beeCount	 Number of bees in the map
		* @param cropChance  Chance that a location will have a crop on it, out of 100.
		*					 For example, cropChance = 50 means 50/100 = 1/2 chance
		* @throw invalid_argument if the given environment dimensions are negative or of size 0
		*/
		BasicMapGenerator(EnvColours envColours, SoybeanOverlays soybeanOverlays, int envSizeX, int envSizeY, int beeCount, int cropChance);
	
		/**
		* @brief Generates a populated Environment for the simulation to run, with Honeybees and Soybeans randomly scattered around
		*
		* @param agentController the AgentController to which Honeybees in the generated Environment will be added to
		* @return the generated Environment
		*/
		Environment generateEnvironment(AgentController& agentController);
	
	private:
	
		/// @brief length of the map
		int envSizeX;
	
		/// @brief height of the map
		int envSizeY;
	
		/// @brief number of bees in the map
		int beeCount;
	
		/// @brief chance that a location will have a crop on it, out of 100. For example, cropChance = 50 means 50 / 100 = 1 / 2 chance
		int cropChance;
	
		/// @brief colours to be used by the locations in map
		EnvColours envColours;
	
		/// @brief pointers to the overlays to be used by Soybeans
		SoybeanOverlays soybeanOverlays;
};

#endif
