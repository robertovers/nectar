#include <gtest/gtest.h>
#include "../src/honeybee.hpp"
#include "../src/location.hpp"
#include "../src/agentController.hpp"
#include "../src/basicMapGenerator.hpp"

// Test locations are added to bee memory. 
TEST(HoneybeeTest, MemoryIsAdded) {
    bool in_mem;
    shared_ptr<HoneyBee> bee = std::make_shared<HoneyBee>();
    shared_ptr<Location> loc = std::make_shared<Location>();
    
    in_mem = bee->inMemory(loc);

    EXPECT_EQ(in_mem, false);

    bee->addMemory(loc);

    in_mem = bee->inMemory(loc);

    EXPECT_EQ(in_mem, true);
}

// Test memory queue size is correctly limited to the memory limit attribute.
TEST(HoneybeeTest, MemoryIsLimited) {
    int mem_lim, mem_size;
    shared_ptr<HoneyBee> bee = std::make_shared<HoneyBee>();
    shared_ptr<Location> loc = std::make_shared<Location>();
    
    mem_lim = bee->getMemoryLimit();
    
    // add more locations than the limit
    for (int i=0; i<mem_lim+2; i++) { 
        bee->addMemory(loc);
    }

    mem_size = bee->getMemory().size();
    
    EXPECT_EQ(mem_size, mem_lim);
}

// Test memory correctly follows a first-in-first out cycle.
TEST(HoneybeeTest, MemoryIsFIFO) {
    int mem_lim;
    bool in_mem;
    shared_ptr<Location> front, back;
    shared_ptr<HoneyBee> bee = std::make_shared<HoneyBee>();
    shared_ptr<Location> loc1 = std::make_shared<Location>();
    shared_ptr<Location> loc2 = std::make_shared<Location>();

    mem_lim = bee->getMemoryLimit();

    bee->addMemory(loc1);
    front = bee->getMemory().front();

    EXPECT_EQ(front, loc1);

    // push memory to back of queue
    for (int i=0; i<mem_lim-1; i++) {
        bee->addMemory(loc2);
    }

    back = bee->getMemory().back();

    EXPECT_EQ(back, loc1);

    // now push memory out of queue
    bee->addMemory(loc2);

    in_mem = bee->inMemory(loc1);

    EXPECT_EQ(in_mem, false); 
}

// Test behaviour is correctly set to HarvestingNotified for bees in the
// vicinity of the waggle dance
TEST(HoneybeeTest, WaggleDanceBehaviour) {
    BasicMapGenerator gen = BasicMapGenerator(EnvColours(), SoybeanOverlays(), 50, 50, 1, 0);
    auto ac = std::make_shared<AgentController>();
    auto env = std::make_shared<Environment>(gen.generateEnvironment(*ac)); 
    auto loc = std::make_shared<Location>(10, 10);

    auto hive = env->getHive();
    int hive_x = hive->getX();
    int hive_y = hive->getY();

    shared_ptr<HoneyBee> notifier = std::make_shared<HoneyBee>(hive_x, hive_y); 
    shared_ptr<HoneyBee> bee_in_1 = std::make_shared<HoneyBee>(hive_x+1, hive_y+1); 
    shared_ptr<HoneyBee> bee_in_2 = std::make_shared<HoneyBee>(hive_x+2, hive_y+2); 
    shared_ptr<HoneyBee> bee_out = std::make_shared<HoneyBee>(hive_x+3, hive_y+3); 

    // add agents to controller
    ac->addAgent(notifier);
    ac->addAgent(bee_in_1);
    ac->addAgent(bee_in_2);
    ac->addAgent(bee_out);

    // add agents to locations
    env->getLocation(hive_x, hive_y)->addAgent(*notifier);
    env->getLocation(hive_x, hive_y)->addAgent(*bee_in_1);
    env->getLocation(hive_x+1, hive_y+1)->addAgent(*bee_in_2);
    env->getLocation(hive_x+5, hive_y+5)->addAgent(*bee_out);

    // perform waggle dance
    notifier->waggle(*env, hive, loc);

    EXPECT_EQ(HoneybeeBehaviour::HarvestingNotified, bee_in_1->getBehaviour());
    EXPECT_EQ(HoneybeeBehaviour::HarvestingNotified, bee_in_2->getBehaviour());
    EXPECT_NE(HoneybeeBehaviour::HarvestingNotified, bee_out->getBehaviour());
}

// Test target is correctly set for bees in the vicinity of the waggle dance
TEST(HoneybeeTest, WaggleDanceTarget) {
    BasicMapGenerator gen = BasicMapGenerator(EnvColours(), SoybeanOverlays(), 50, 50, 1, 0);
    auto ac = std::make_shared<AgentController>();
    auto env = std::make_shared<Environment>(gen.generateEnvironment(*ac)); 
    auto loc = std::make_shared<Location>(10, 10);

    auto hive = env->getHive();
    int hive_x = hive->getX();
    int hive_y = hive->getY();

    shared_ptr<HoneyBee> notifier = std::make_shared<HoneyBee>(hive_x, hive_y); 
    shared_ptr<HoneyBee> bee_in_1 = std::make_shared<HoneyBee>(hive_x+1, hive_y+1); 
    shared_ptr<HoneyBee> bee_in_2 = std::make_shared<HoneyBee>(hive_x+2, hive_y+2); 
    shared_ptr<HoneyBee> bee_out = std::make_shared<HoneyBee>(hive_x+3, hive_y+3); 

    // add agents to controller
    ac->addAgent(notifier);
    ac->addAgent(bee_in_1);
    ac->addAgent(bee_in_2);
    ac->addAgent(bee_out);

    // add agents to locations
    env->getLocation(hive_x, hive_y)->addAgent(*notifier);
    env->getLocation(hive_x, hive_y)->addAgent(*bee_in_1);
    env->getLocation(hive_x+1, hive_y+1)->addAgent(*bee_in_2);
    env->getLocation(hive_x+5, hive_y+5)->addAgent(*bee_out);

    // perform waggle dance
    notifier->waggle(*env, hive, loc);

    EXPECT_EQ(loc, bee_in_1->getTarget());
    EXPECT_EQ(loc, bee_in_2->getTarget());
}