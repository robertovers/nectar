#include <gtest/gtest.h>
#include "../src/basicMapGenerator.hpp"
#include "../src/environment.hpp"
#include "../src/honeybee.hpp"

// initial plant count is correct
TEST(EnvironmentTest, PlantCount) {
    BasicMapGenerator mp = BasicMapGenerator(3, 3, 0, 100);
    Environment env = mp.generateEnvironment();

    EQ(env.plantCount(), 9);
}

TEST(EnvironmentTest, AgentCount) {
    BasicMapGenerator mp = BasicMapGenerator(3, 3, 7, 0);
    Environment env = mp.generateEnvironment();

    // initial agent count is correct
    EQ(env.agentCount(), 7);

    // add agent
    Honeybee bee = HoneyBee();
}