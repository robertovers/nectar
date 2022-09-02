#include <gtest/gtest.h>
#include "../src/basicMapGenerator.hpp"


TEST(BasicMapGeneratorTest, MapSize) {
    // Invalid map size options
    EXPECT_THROW(BasicMapGenerator(-1, 1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(0, 1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(1, -1, 0, 0), std::invalid_argument);
    EXPECT_THROW(BasicMapGenerator(-1, 0, 0, 0), std::invalid_argument);
    
    // Check that generated environment is right size
    int x = 3;
    int y = 4;
    int bees = 3;
    int cropChance = 50;
    Environment env = BasicMapGenerator(x, y, bees, cropChance).generateEnvironment(AgentController());
    EXPECT_EQ(env.getSize(), x * y);
    EXPECT_EQ(env.getWidth(), x);
    EXPECT_EQ(env.getHeight(), y);
}

TEST(BasicMapGeneratorTest, BeeCount) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(BasicMapGeneratorTest, SoybeanCount) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}