#include <gtest/gtest.h>
#include "../src/hive.hpp"

// Ensure Hive is not initialised as a plant
TEST(HiveTest, IsNotPlant) {
    shared_ptr<sf::Color> hive_col = std::make_shared<sf::Color>(sf::Color::Red);
    shared_ptr<Hive> hive = std::make_shared<Hive>(0, 0, hive_col);
    bool isPlant = hive->isPlant();
    EXPECT_EQ(isPlant, false);
}

// Test nectar depositing is correct
TEST(HiveTest, DepositNectar) {
    int nectar;
    shared_ptr<sf::Color> hive_col = std::make_shared<sf::Color>(sf::Color::Red);
    shared_ptr<Hive> hive = std::make_shared<Hive>(0, 0, hive_col);

    nectar = hive->getNectar();

    EXPECT_EQ(nectar, 0);

    hive->depositNectar(1);
    
    nectar = hive->getNectar();

    EXPECT_EQ(nectar, 1);
}