#include <gtest/gtest.h>
#include "../src/basicMapGenerator.hpp"
#include "../src/environment.hpp"
#include "../src/honeybee.hpp"

// initial plant count is correct
TEST(EnvironmentTest, PlantCount) {
    BasicMapGenerator mp = BasicMapGenerator(3, 3, 0, 100);
    Environment env = mp.generateEnvironment();

    EQ(env.plantCount(), 8);
}

TEST(EnvironmentTest, AgentCount) {
    BasicMapGenerator mp = BasicMapGenerator(3, 3, 7, 0);
    Environment env = mp.generateEnvironment();

    // initial agent count is correct
    EQ(env.agentCount(), 7);
}

TEST(EnvironmentTest, LocationTest) {
    auto env = Environment(3, 3);
    auto loc = env.getLocation(3, 2);
    EQ(loc->getX(), 3);
    EQ(loc->getY(), 2);

    loc = env.getLocation(2, 3);
    EQ(loc->getX(), 2);
    EQ(loc->getY(), 3);
}

TEST(EnvironmentTest, LocationTest) {
    auto env = Environment(3, 3);
    auto loc = env.getLocation(3, 2);
    EQ(loc->getX(), 3);
    EQ(loc->getY(), 2);

    loc = env.getLocation(2, 3);
    EQ(loc->getX(), 2);
    EQ(loc->getY(), 3);
}