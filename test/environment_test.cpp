#include <gtest/gtest.h>
#include "../src/basicMapGenerator.hpp"
#include "../src/agentController.hpp"
#include "../src/environment.hpp"
#include "../src/honeybee.hpp"

// initial plant count is correct
TEST(EnvironmentTest, PlantCount) {
    BasicMapGenerator mp = BasicMapGenerator(3, 3, 0, 100);
    auto ac = AgentController();
    Environment env = mp.generateEnvironment(ac);

    EXPECT_EQ(env.plantCount(), 8);
}

TEST(EnvironmentTest, AgentCount) {
    BasicMapGenerator mp = BasicMapGenerator(3, 3, 7, 0);
    auto ac = AgentController();
    Environment env = mp.generateEnvironment(ac);

    // initial agent count is correct
    EXPECT_EQ(env.agentCount(), 7);
}

TEST(EnvironmentTest, LocationTest) {
    auto env = Environment(3, 3);
    auto loc = env.getLocation(3, 2);
    EXPECT_EQ(loc->getX(), 3);
    EXPECT_EQ(loc->getY(), 2);

    loc = env.getLocation(2, 3);
    EXPECT_EQ(loc->getX(), 2);
    EXPECT_EQ(loc->getY(), 3);
}
