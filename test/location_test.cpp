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
    int id_a = agent.getID();
    auto agents = loc.getAgents();
    bool found = false;

    auto equal_id = [id_a](Agent& b) { return b.getID() == id_a; };
    auto it = std::find_if(agents.begin(), agents.end(), equal_id);
    if (it != agents.end()) found = true;
    EXPECT_EQ(found, false);

    loc.addAgent(agent);
    agents = loc.getAgents();
    EXPECT_EQ(loc.numAgents(), 1);

    auto equal_id_2 = [id_a](Agent& b) { return b.getID() == id_a; };
    auto it_2 = std::find_if(agents.begin(), agents.end(), equal_id_2);
    if (it_2 != agents.end()) found = true;

    EXPECT_EQ(found, true);
}

TEST(LocationTest, AddAnotherAgent) {
    Location loc = Location();
    HoneyBee agent = HoneyBee();
    loc.addAgent(agent);

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
    Location loc = Location();
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
    Location loc;
    HoneyBee agent1 = HoneyBee();
    HoneyBee agent2 = HoneyBee();

    // empty location
    loc = Location();
    EXPECT_NO_THROW(loc.clearAgents());
    EXPECT_EQ(loc.numAgents(), 0);

    // containing one agent
    loc = Location();
    loc.addAgent(agent1);
    EXPECT_NO_THROW(loc.clearAgents());
    EXPECT_EQ(loc.numAgents(), 0);

    // containing multiple agents
    loc = Location();
    loc.addAgent(agent1);
    loc.addAgent(agent2);
    EXPECT_NO_THROW(loc.clearAgents());
    EXPECT_EQ(loc.numAgents(), 0);
}