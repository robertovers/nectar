/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file rowMapGenerator.hpp
 * @brief MapGenerator for generating an Environment with Soybeans and empty Locations in alternating, horizontal, 1-block wide rows. Honeybees are randomly scattered around. 
 * @date 2022-09-28
 */
#ifndef rowmapgenerator_hpp
#define rowmapgenerator_hpp

#include "mapGenerator.hpp"
#include "honeybee.hpp"
#include "soybean.hpp"

 /**
  * @brief MapGenerator for generating an Environment with Soybeans and empty Locations in alternating, horizontal, 1-block wide rows. Honeybees are randomly scattered around. 
  */
class RowMapGenerator : MapGenerator {

	public:
		/**
		* @brief Create a new BasicMapGenerator with settings for generated map
		*
		* @param envColours  Colours to be used by the locations in map
		* @param soybeanOverlays Pointers to the overlays to be used by Soybeans
		* @param envSizeX	 Length of the map
		* @param envSizeY	 Height of the map
		* @param beeCount	 Number of bees in the map
		* @throw invalid_argument if the given environment dimensions are negative or of size 0
		*/
		RowMapGenerator(EnvColours envColours, SoybeanOverlays soybeanOverlays, int envSizeX, int envSizeY, int beeCount);

		/**
		* @brief Generates a populated Environment for the simulation to run, with Soybeans and empty Locations in alternating, horizontal, 1-block wide rows. Honeybees are randomly scattered around. 
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

		/// @brief colours to be used by the locations in map
		EnvColours envColours;

		/// @brief pointers to the overlays to be used by Soybeans
		SoybeanOverlays soybeanOverlays;

};

#endif