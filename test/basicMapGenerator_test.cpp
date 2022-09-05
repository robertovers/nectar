#include <gtest/gtest.h>
#include "../src/basicMapGenerator.hpp"

// Invalid map size options
TEST(BasicMapGeneratorTest, InvalidMapSize) {
    EXPECT_THROW(BasicMapGenerator(-1, 1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(0, 1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(1, -1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(-1, 0, 0, 0), std::invalid_argument);
}

// Generated environment is right size
TEST(BasicMapGeneratorTest, CorrectMapSize) {
    int x = 3;
    int y = 4;
    int bees = 3;
    int cropChance = 50;
    Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
    EXPECT_EQ(env.getSize(), x * y);
    EXPECT_EQ(env.getWidth(), x);
    EXPECT_EQ(env.getHeight(), y);
}

// AgentController is controlling bees
TEST(BasicMapGeneratorTest, AgentControllerBeeCount) {
    int x = 3;
    int y = 4;
    int beeValues = [3, 0, x * y, x * y + 5];
    int cropChance = 50;

    for (int bees : beeValues) {
        AgentController controller = AgentController();
        BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(controller);
        EXPECT_EQ(controller.getAgents().size(), bees);
    }
}

// Environment contains bees
TEST(BasicMapGeneratorTest, BeeCount) {
    int x = 3;
    int y = 4;
    int beeValues = [3, 0, x * y, x * y + 5];
    int cropChance = 50;

    for (int bees : beeValues) {
        Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
        EXPECT_EQ(env.agentCount(), bees);
    }
}

// Environment contains appropriate amount of crops
//TEST(BasicMapGeneratorTest, PlantCount) {
//    int x = 5;
//    int y = 10;
//    int bees = 3;
//    int cropChances = [0, 50, 100];
//
//    for (int cropChance : cropChances) {
//        Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
//        // TODO: figure out appropriate test
//        // TODO: add when advanced bee behavior branch is merged, or use of env.plantCount()
//    }
//}
