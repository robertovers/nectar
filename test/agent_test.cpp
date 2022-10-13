#include <gtest/gtest.h>
#include "../src/honeybee.hpp"
#include "../src/basicMapGenerator.hpp"
#include "../src/utility.hpp"

// Test location correctly retreived
TEST(AgentTest, LocationIsRetrieved) {
    BasicMapGenerator gen = BasicMapGenerator(EnvColours(), SoybeanOverlays(), 50, 50, 1, 0);
    auto ac = std::make_shared<AgentController>();
    auto env = std::make_shared<Environment>(gen.generateEnvironment(*ac));

    shared_ptr<HoneyBee> bee1 = std::make_shared<HoneyBee>(0, 0);
    shared_ptr<Location> loc1 = bee1->getLocation(*env);
    shared_ptr<Location> loc2 = env->getLocation(0, 0);

    EXPECT_EQ(loc1, loc2);

    shared_ptr<HoneyBee> bee2 = std::make_shared<HoneyBee>(49, 49);
    shared_ptr<Location> loc3 = bee2->getLocation(*env);
    shared_ptr<Location> loc4 = env->getLocation(49, 49);

    EXPECT_EQ(loc3, loc4);
    
    shared_ptr<HoneyBee> bee3 = std::make_shared<HoneyBee>(-1, -1);
    shared_ptr<Location> loc5 = bee3->getLocation(*env);

    EXPECT_EQ(loc5, nullptr);

    shared_ptr<HoneyBee> bee4 = std::make_shared<HoneyBee>(50, 50);
    shared_ptr<Location> loc6 = bee4->getLocation(*env);
    
    EXPECT_EQ(loc6, nullptr);
}

// Test IDs are unique
TEST(AgentTest, IDisUnique) {
    shared_ptr<HoneyBee> bee1 = std::make_shared<HoneyBee>();
    shared_ptr<HoneyBee> bee2 = std::make_shared<HoneyBee>();
    EXPECT_NE(bee1->getID(), bee2->getID());
}

// Test target is set
TEST(AgentTest, TargetIsSet) {
    BasicMapGenerator gen = BasicMapGenerator(EnvColours(), SoybeanOverlays(), 50, 50, 1, 0);
    auto ac = std::make_shared<AgentController>();
    auto env = std::make_shared<Environment>(gen.generateEnvironment(*ac));

    shared_ptr<Location> loc1 = env->getLocation(0, 0);
    shared_ptr<HoneyBee> bee1 = std::make_shared<HoneyBee>();

    bee1->setTarget(loc1);
    EXPECT_EQ(bee1->getTarget(), loc1);
}
