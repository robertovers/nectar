#include <gtest/gtest.h>
#include "../src/utility.hpp"

void eq_params(Parameters params, int rows, int columns, int scale, int bees, float prob);

// Test that the check limits function adjusts parameter elements correctly
TEST(UtilityTest, CheckLimits) {

    // Default parameter values
    Parameters params = Parameters();
    eq_params(params, 100, 100, 8, 50, 0.1);

    // Check limits shuold not change valid parameter values
    params.check_limits();
    eq_params(params, 100, 100, 8, 50, 0.1);

    // Combinations of invalid values
    params.rows = 0;            // Under min
    params.columns = 401;      // Over max
    params.scale = 0;           // Under min
    params.bees = 10001;      // Over max
    params.soybean_p = -1;       // Under min
    params.check_limits();
    eq_params(params, 1, 400, 1, 10000, 0.05);

    params.rows = 401;       // Over max
    params.columns = 0;             // Under min
    params.scale = 51;     // Over max
    params.bees = -1;               // Under min
    params.soybean_p = 2;           // Over max
    params.check_limits();
    eq_params(params, 400, 1, 50, 0, 1);

    // Combination of correct and incorrect values
    params.soybean_p = 0.5;
    params.columns = 401;
    params.check_limits();
    eq_params(params, 400, 400, 50, 0, 0.5);
}

void eq_params(Parameters params, int rows, int columns, int scale, int bees, float prob){
    EXPECT_EQ(params.rows, rows);
    EXPECT_EQ(params.columns, columns);
    EXPECT_EQ(params.scale, scale);
    EXPECT_EQ(params.bees, bees);
    EXPECT_EQ(params.soybean_p, prob);
}