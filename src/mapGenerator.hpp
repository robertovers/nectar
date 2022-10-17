/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file mapGenerator.hpp
 * @brief Abstract factory class for generating an Environment prepopulated with Agents
 * @date 2022-09-28
 */

#ifndef mapgenerator_hpp
#define mapgenerator_hpp

#include "environment.hpp"
#include "agentController.hpp"

/**
* @brief Abstract factory class for generating an Environment prepopulated with Agents
* 
* Subclasses create specific Environments by defining their own version of generateEnvironment(). 
* They can also define variables that tweak the specifics of the Environment to be generated.
*/
class MapGenerator {

	public:
		/**
		* @brief Generates a populated Environment for the simulation to run
		* 
		* @param agentController the AgentController to which Agents in the generated Environment will be added to
		* @return the generated Environment 
		*/
		virtual Environment generateEnvironment(AgentController& agentController) = 0;
	};

#endif