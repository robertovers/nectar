#include <gtest/gtest.h>
#include <algorithm>
#include "../src/location.hpp"
#include "../src/honeybee.hpp"

// coords are set and get correctly
TEST(LocationTest, SetCoords) {
    int x = 1;
    int y = 1;
    Location loc = Location(x, y);
    EXPECT_EQ(loc.getX(), x);
    EXPECT_EQ(loc.getY(), y);
}

// agents are added
TEST(LocationTest, AddAgent) {
    // add new agent to empty location
    Location loc = Location();
    HoneyBee agent = HoneyBee();
    loc.addAgent(agent);
    EXPECT_EQ(loc.numAgents(), 1);
    // TODO: check agent is actually added

    // add new agent to location containing another agent
    HoneyBee anotherAgent = HoneyBee();
    loc.addAgent(anotherAgent);
    EXPECT_EQ(loc.numAgents(), 2);

    // re-add existing agent
    loc.addAgent(agent);
    EXPECT_EQ(loc.numAgents(), 2);
}

// agent is removed
TEST(LocationTest, RemoveAgent) {
    location loc = Location();
    HoneyBee agent = HoneyBee();

    // try to remove non-existing agent from empty
    EXPECT_NO_THROW(loc.removeAgent(agent));
    EXPECT_EQ(loc.numAgents(), 0);

    loc.addAgent(agent);
    HoneyBee anotherAgent = HoneyBee();
    // try to remove non-existing agent from non-empty
    EXPECT_NO_THROW(loc.removeAgent(anotherAgent));
    EXPECT_EQ(loc.numAgents(), 1);
    
    loc.addAgent(anotherAgent);
    // remove existing agent when more than one agent
    loc.removeAgent(agent);
    EXPECT_EQ(loc.numAgents(), 1);

    // remove existing agent when only agent
    loc.removeAgent(anotherAgent);
    EXPECT_EQ(loc.numAgents(), 0);
}

// all agents are removed
TEST(LocationTest, ClearAgents) {
    // empty location
    location loc = Location();
    EXPECT_NO_THROW(loc.clearAgents());
    EXPECT_EQ(loc.numAgents(), 0);

    // containing one agent
    location loc = Location();
    loc.addAgent(HoneyBee());
    EXPECT_NO_THROW(loc.clearAgents());
    EXPECT_EQ(loc.numAgents(), 0);

    // containing multiple agents
    location loc = Location();
    loc.addAgent(HoneyBee());
    loc.addAgent(HoneyBee());
    EXPECT_NO_THROW(loc.clearAgents());
    EXPECT_EQ(loc.numAgents(), 0);
}
