#include <gtest/gtest.h>
#include "../src/soybean.hpp"
#include "../src/utility.hpp"

// Test soybean initialised
TEST(SoybeanTest, SoybeanInit) {
    SoybeanOverlays overlays = SoybeanOverlays();
    shared_ptr<sf::Color> colour = std::make_shared<sf::Color>(sf::Color::Black);
    shared_ptr<Soybean> soybean = std::make_shared<Soybean>(0, 0, colour, colour, colour, overlays);

    EXPECT_NE(soybean, nullptr);
}