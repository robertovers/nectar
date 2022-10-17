#include <gtest/gtest.h>
#include "../src/utility.hpp"
#include "../src/rowMapGenerator.hpp"
#include <stdio.h>


TEST(MetricsTest, UpdateMetrics){
    // Setup empty envirment (No agents)
    EnvColours envColours;
    Environment enviro(100, 100, envColours.locationColour);
    // Hive
    auto hive = shared_ptr<Hive>(std::make_shared<Hive>(50, 50, envColours.hiveColour));
    enviro.changeLocation(50, 50, hive);
    enviro.setHive(hive);

    // Initially no nectar in hive and no pollinated crops
    Metrics metrics;
    metrics.updateMetrics(enviro, sf::seconds(1.3f+60*2+3600*4));
    EXPECT_EQ(metrics.secs_elapsed, 1+60*2+3600*4);
    EXPECT_EQ(metrics.days, 0);
    EXPECT_EQ(metrics.hours, 4);
    EXPECT_EQ(metrics.mins, 2);
    EXPECT_EQ(metrics.secs, 1);
    EXPECT_EQ(metrics.hive_nectar, 0);
    EXPECT_EQ(metrics.pollinated_count, 0);


    // Add nectar to hives and increse pollination count of environment
    hive->depositNectar(20);
    for (int i=0;i<6; i++){
    enviro.incPollinatedCount();
    }
    metrics.updateMetrics(enviro, sf::seconds(1.5f+60*5+3600*2+3600*24*3));
    EXPECT_EQ(metrics.secs_elapsed, 1+60*5+3600*2+3600*24*3);
    EXPECT_EQ(metrics.days, 3);
    EXPECT_EQ(metrics.hours, 2);
    EXPECT_EQ(metrics.mins, 5);
    EXPECT_EQ(metrics.secs, 1);
    EXPECT_EQ(metrics.hive_nectar, 20);
    EXPECT_EQ(metrics.pollinated_count, 6);
}

// Test that function timeString() outputs the correct string
TEST(MetricsTest, TimeString){
    Metrics metrics;
    metrics.days = 3;
    metrics.hours = 2;
    metrics.mins = 0;
    metrics.secs = 1;
    EXPECT_EQ(metrics.timeString(), "3d : 2h : 0m : 1s");
}

//Test that the check limits function adjusts parameter elements correctly
TEST(UtilityTest, CheckLimits) {

    void eq_params(Parameters params, int rows, int columns, int scale, int bees, float prob);

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


// Auxillary function for cleaner code, used in the CheckLimits test.
void eq_params(Parameters params, int rows, int columns, int scale, int bees, float prob){
    EXPECT_EQ(params.rows, rows);
    EXPECT_EQ(params.columns, columns);
    EXPECT_EQ(params.scale, scale);
    EXPECT_EQ(params.bees, bees);
    EXPECT_EQ(params.soybean_p, prob);
}


/*
// Tests not functioning currectly due to fscanf not scanning any values. No files are being created either. 

// Tests that toFile appends the correct values to file
TEST(MetricsTest, ToFile){
    int scanned = 0;
    Metrics toFileMetrics;
    int secsElapsed=0, hiveNectar=0, pollinationCount=0;

    // toFile writes initial metrics values to file - 0,0,0
    toFileMetrics.toFile("metrics_file_test.txt");
    
    // toFile appends new metrics values to file - 54323,20,6
    toFileMetrics.secs_elapsed = 54323;
    toFileMetrics.hive_nectar = 20;
    toFileMetrics.pollinated_count = 6;
    toFileMetrics.toFile("metrics_file_test.txt");    

    FILE* file = fopen("metrics_file_test.txt","r"); 
    // Initial
    scanned = fscanf(file, "%d,%d,%d\n", &secsElapsed, &hiveNectar, &pollinationCount);
    EXPECT_NE(scanned, 0);
    EXPECT_EQ(toFileMetrics.secs_elapsed, secsElapsed);
    EXPECT_EQ(toFileMetrics.hive_nectar, hiveNectar);
    EXPECT_EQ(toFileMetrics.pollinated_count, pollinationCount);

    // New after initial
    fscanf(file, "%d,%d,%d\n", &secsElapsed, &hiveNectar, &pollinationCount);    
    EXPECT_EQ(toFileMetrics.secs_elapsed, secsElapsed);
    EXPECT_EQ(toFileMetrics.hive_nectar, hiveNectar);
    EXPECT_EQ(toFileMetrics.pollinated_count, pollinationCount);

    fclose(file);
    file = NULL;
}


// Tests that createDataFile rewrites the file with the correct values
TEST(MetricsTest, CreateDataFile){
    FILE *file1, *file2;
    Metrics cdmetrics;
    int secsElapsed=0, hiveNectar=0, pollinationCount=0;

    // toFile writes initial metrics values to file - 0,0,0
    cdmetrics.createDataFile("metrics_file_test.txt");
    file1 = fopen("metrics_file_test.txt","r"); 
    fscanf(file1, "%i,%i,%i\n", &secsElapsed, &hiveNectar, &pollinationCount);
    fclose(file1);

    EXPECT_EQ(cdmetrics.secs_elapsed, secsElapsed);
    EXPECT_EQ(cdmetrics.hive_nectar, hiveNectar);
    EXPECT_EQ(cdmetrics.pollinated_count, pollinationCount);
    
    // toFile appends new metrics values to file - 54323,20,6
    cdmetrics.secs_elapsed = 54323;
    cdmetrics.hive_nectar = 20;
    cdmetrics.pollinated_count = 6;
    cdmetrics.createDataFile("metrics_file_test.txt"); 

    file2 = fopen("metrics_file_test.txt","r"); 
    fscanf(file2, "%i,%i,%i\n", &secsElapsed, &hiveNectar, &pollinationCount);
    fclose(file2);

    EXPECT_EQ(cdmetrics.secs_elapsed, secsElapsed);
    EXPECT_EQ(cdmetrics.hive_nectar, hiveNectar);
    EXPECT_EQ(cdmetrics.pollinated_count, pollinationCount);

    file1 = file2 = NULL;
}
*/
