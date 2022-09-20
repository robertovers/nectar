#include <gtest/gtest.h>
#include "../src/honeybee.hpp"
#include "../src/location.hpp"
#include "../src/agentController.hpp"
#include "../src/basicMapGenerator.hpp"

// Test scanning method correctly returns a shared pointer to a found plant.
TEST(HoneybeeTest, ScanFindsPlant) {
    shared_ptr<Location> plant, found_plant;
    AgentController ac = AgentController();
    Environment env = BasicMapGenerator(10, 10, 0, 0).generateEnvironment(ac);
    shared_ptr<HoneyBee> bee = std::make_shared<HoneyBee>(5, 5);
    ac.addAgent(bee);

    // search without any plants 
    found_plant = bee->scanForPlants(env);

    EXPECT_EQ(found_plant, nullptr);

    // add plant, then search again
    plant = std::make_shared<Plant>(7, 7);
    env.changeLocation(7, 7, plant);
    found_plant = bee->scanForPlants(env);

    EXPECT_EQ(found_plant, plant);
}

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