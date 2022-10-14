#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "../src/agentController.hpp"
#include "../src/honeybee.hpp"
#include "../src/agent.hpp"
#include "../src/environment.hpp"

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

TEST(AgentControllerTest, RemoveAgent) {
    AgentController ac = AgentController();
    shared_ptr<HoneyBee> agent = std::make_shared<HoneyBee>();
    int id_a = agent->getID();
    auto agents = ac.getAgents();
    bool found = false;
    
    ac.addAgent(agent);

    auto equal_id = [id_a](shared_ptr<Agent> b) { return b->getID() == id_a; };
    auto it = std::find_if(agents.begin(), agents.end(), equal_id);
    if (it != agents.end()) found = true;

    EXPECT_EQ(found, true); 

    ac.removeAgent(agent);
    agents = ac.getAgents();

    auto equal_id_2 = [id_a](shared_ptr<Agent> b) { return b->getID() == id_a; };
    auto it_2 = std::find_if(agents.begin(), agents.end(), equal_id_2);
    if (it_2 != agents.end()) {
        found = true;
    } else {
        found = false;
    }

    EXPECT_EQ(found, false); 
}

// mock agent class for update and draw tests
class MockAgent : public HoneyBee {
public:
    MOCK_METHOD(void, draw, (sf::RenderTarget& target, sf::RenderStates states), (override, const));  // dont know if draw test will work bc of sf
    MOCK_METHOD(void, update, (Environment& environment), (override));
};

TEST(AgentControllerTest, UpdateAgents) {
    MockAgent agent1;
    auto agentPointer = std::shared_ptr<Agent>(new MockAgent()); //std::make_shared<Agent>(agent1);
    //MockAgent agent2;
    //MockAgent agent3;
    //MockAgent agents[] = { agent1, agent2, agent3 };

    AgentController controller = AgentController();
    controller.addAgent(agentPointer);
    EXPECT_CALL(agent1, update(::testing::_)).Times(::testing::AtLeast(1));

    /*for (int i = 0; i < 3; i++) {
        controller.addAgent(shared_ptr<Agent>(agents[i]));
        EXPECT_CALL(agents[i], update()).Times(::testing::AtLeast(1));
    }*/
    
    auto env = Environment(3, 3, std::make_shared<sf::Color>());
    controller.updateAgents(env);
}

//TEST(AgentControllerTest, DrawAgents) {
//    MockAgent agent1;
//    MockAgent agent2;
//    MockAgent agent3;
//    MockAgent agents[] = { agent1, agent2, agent3 };
//
//    AgentController controller = AgentController();
//
//    for (int i = 0; i < 3; i++) {
//        controller.addAgent(agents[i]);
//        EXPECT_CALL(agents[i], draw()).Times(::testing::AtLeast(1));
//    }
//
//    controller.draw();
//}