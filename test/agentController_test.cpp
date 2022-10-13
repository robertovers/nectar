#include <gtest/gtest.h>
#include <algorithm>
#include "../src/agentController.hpp"
#include "../src/honeybee.hpp"

TEST(AgentControllerTest, AddAgent) {
    AgentController ac = AgentController();
    shared_ptr<HoneyBee> agent = std::make_shared<HoneyBee>();
    int id_a = agent->getID();
    auto agents = ac.getAgents();
    bool found = false;

    auto equal_id = [id_a](shared_ptr<Agent> b) { return b->getID() == id_a; };
    auto it = std::find_if(agents.begin(), agents.end(), equal_id);
    if (it != agents.end()) found = true;
    EXPECT_EQ(found, false);
    
    ac.addAgent(agent);
    agents = ac.getAgents();
    
    auto equal_id_2 = [id_a](shared_ptr<Agent> b) { return b->getID() == id_a; };
    auto it_2 = std::find_if(agents.begin(), agents.end(), equal_id_2);
    if (it_2 != agents.end()) found = true;

    EXPECT_EQ(found, true);
}