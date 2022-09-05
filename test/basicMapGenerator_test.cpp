#include <gtest/gtest.h>
#include "../src/basicMapGenerator.hpp"

// Invalid map size options - 0 and negatives
TEST(BasicMapGeneratorTest, InvalidMapSize) {
    EXPECT_THROW(BasicMapGenerator(-1, 1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(0, 1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(1, -1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(-1, 0, 0, 0), std::invalid_argument);
}

// Generated environment is right size
TEST(BasicMapGeneratorTest, CorrectMapSize) {
    int bees = 3;
    int cropChance = 50;
    std::vector<int> xs{ 1, 1, 3, 3, 50 };
    std::vector<int> ys{ 1, 4, 1, 4, 50 };
    for (int i = 0; i = xs.size(); i++) {
        int x = xs[i];
        int y = ys[i];
        Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
        EXPECT_EQ(env.getSize(), x * y);
        EXPECT_EQ(env.getWidth(), x);
        EXPECT_EQ(env.getHeight(), y);
    }
}

// AgentController is controlling bees
TEST(BasicMapGeneratorTest, AgentControllerBeeCount) {
    int x = 3;
    int y = 4;
    std::vector<int> beeValues{ 0, 3, x * y, x * y + 5 };
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
    std::vector<int> beeValues{ 0, 3, x * y, x * y + 5 };
    int cropChance = 50;

    for (int bees : beeValues) {
        Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
        EXPECT_EQ(env.agentCount(), bees);
    }
}

// Environment contains appropriate amount of crops
TEST(BasicMapGeneratorTest, PlantCount) {
    int x = 5;
    int y = 10;
    int bees = 3;

    // no crops
    int cropChance = 0;
    Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
    EXPECT_EQ(0, env.plantCount());

    // some crops
    cropChance = 50;
    env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
    EXPECT_NEAR(env.plantCount(), (x * y) / 2, (x * y) / 4); // TODO: determine if margin of error is appropriate
    
    // all crops
    cropChance = 100;
    env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
    EXPECT_EQ(env.plantCount(), x*y);
}
