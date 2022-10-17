#include <gtest/gtest.h>
#include "../src/utility.hpp"

// Test that the check limits function adjusts parameter elements correctly
TEST(UtilityTest, CheckLimits) {

    // Default parameter values
    Parameters params = Parameters();
    eq_params(params, 100, 100, 8, 50, 0.1);

    // Check limits shuold not change valid parameter values
    params.check_limits();
    eq_params(params, 100, 100, 8, 50, 0.1);

    // Combinations of invalid values
    params.rows = 0;
    params.columns = DIMS_MAX+1;
    params.scale = 0;
    params.bees = BEES_MAX+1;
    params.soybean_p = -1
    eq_params(params, 1, DIMS_MAX, 1, BEES_MAX, 0.05);

    params.rows = DIMS_MAX+1;
    params.columns = 0;
    params.scale = SCALE_MAX+1;
    params.bees = -1;
    params.soybean_p = 2;
    eq_params(params, DIMS_MAX, 1, SCALE_MAX, 0, 1);

    // Combination of correct and incorrect values
    params.soybean_p = 0.5
    params.columns = DIMS_MAX+1;
    eq_params(params, DIMS_MAX, DIMS_MAX, SCALE_MAX, 0, 0.5);
}

void eq_params(Parameters params, int rows, int columns, int scale, int bees, float prob){
    EXPECT_EQ(params.rows, rows);
    EXPECT_EQ(params.columns, columns);
    EXPECT_EQ(params.scale, scale);
    EXPECT_EQ(params.bees, bee);
    EXPECT_EQ(params.soybean_p, prob);
}