#include <gtest/gtest.h>
#include <algorithm>
#include "../src/plant.hpp"
#include "../src/honeybee.hpp"

TEST(PlantTest, IsPlant) {
    shared_ptr<Plant> plant = std::make_shared<Plant>(0, 0, std::make_shared<sf::Color>(sf::Color::Green), std::make_shared<sf::Color>(sf::Color::Green), std::make_shared<sf::Color>(sf::Color::Green));

    bool isPlant = plant->isPlant();
    EXPECT_EQ(isPlant, true);
}

TEST(PlantTest, IsPollinated) {
    shared_ptr<Plant> plant = std::make_shared<Plant>(0, 0, std::make_shared<sf::Color>(sf::Color::Green), std::make_shared<sf::Color>(sf::Color::Green), std::make_shared<sf::Color>(sf::Color::Green));

    bool isPollinated = plant->isPollinated();
    EXPECT_EQ(isPollinated, false);

    plant->pollinate();

    isPollinated = plant->isPollinated();
    EXPECT_EQ(isPollinated, true);
}
