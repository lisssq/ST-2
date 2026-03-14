// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;

TEST(CircleTest, Constructor) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
    EXPECT_NEAR(2 * PI * 5.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 25.0, c.getArea(), EPS);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(10.0, c.getRadius());
    EXPECT_NEAR(2 * PI * 10.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 100.0, c.getArea(), EPS);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    double ference = 2 * PI * 7.0;
    c.setFerence(ference);
    EXPECT_NEAR(7.0, c.getRadius(), EPS);  
    EXPECT_NEAR(ference, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 49.0, c.getArea(), EPS);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    double area = PI * 16.0;
    c.setArea(area);
    EXPECT_NEAR(4.0, c.getRadius(), EPS);
    EXPECT_NEAR(2 * PI * 4.0, c.getFerence(), EPS);
    EXPECT_NEAR(area, c.getArea(), EPS);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(-5.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * (-5.0), c.getFerence());
    EXPECT_NEAR(PI * 25.0, c.getArea(), EPS);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(1e6, c.getRadius());
    EXPECT_NEAR(2 * PI * 1e6, c.getFerence(), 1e-6);
    EXPECT_NEAR(PI * 1e12, c.getArea(), 1e-6);
}

TEST(CircleTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_DOUBLE_EQ(1e-6, c.getRadius());
    EXPECT_NEAR(2 * PI * 1e-6, c.getFerence(), 1e-18);
    EXPECT_NEAR(PI * 1e-12, c.getArea(), 1e-18);
}

TEST(CircleTest, ConsistencyAfterSetRadius) {
    Circle c(3.0);
    c.setRadius(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
    EXPECT_NEAR(2 * PI * 5.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 25.0, c.getArea(), EPS);
}

TEST(CircleTest, ConsistencyAfterSetFerence) {
    Circle c(3.0);
    c.setFerence(2 * PI * 4.0);
    EXPECT_NEAR(4.0, c.getRadius(), EPS);
    EXPECT_NEAR(2 * PI * 4.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 16.0, c.getArea(), EPS);
}

TEST(CircleTest, ConsistencyAfterSetArea) {
    Circle c(3.0);
    c.setArea(PI * 36.0);
    EXPECT_NEAR(6.0, c.getRadius(), EPS);
    EXPECT_NEAR(2 * PI * 6.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 36.0, c.getArea(), EPS);
}

TEST(CircleTest, MultipleSetOperations) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(2 * PI * 3.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(4.0, c.getRadius(), EPS);
    EXPECT_NEAR(2 * PI * 4.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 16.0, c.getArea(), EPS);
}

TEST(CircleTest, GetMethods) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
    EXPECT_NEAR(2 * PI * 5.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 25.0, c.getArea(), EPS);
}

TEST(EarthRopeTest, GapIsPositive) {
    double gap = earthAndRopeTask();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapValue) {
    double gap = earthAndRopeTask();
    EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(EarthRopeTest, EarthRadius) {
    Circle earth(6378.1 * 1000);
    EXPECT_DOUBLE_EQ(6378100.0, earth.getRadius());
}

TEST(EarthRopeTest, FerenceAfterAddingMeter) {
    Circle earth(6378.1 * 1000);
    double oldFerence = earth.getFerence();
    earth.setFerence(oldFerence + 1.0);
    EXPECT_NEAR(oldFerence + 1.0, earth.getFerence(), EPS);
}

TEST(PoolTest, TotalCostIsPositive) {
    double cost = poolTask();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolTest, PathArea) {
    Circle pool(3.0);
    Circle poolWithPath(4.0);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double expectedArea = PI * 7.0;
    EXPECT_NEAR(expectedArea, pathArea, EPS);
}

TEST(PoolTest, FenceLength) {
    Circle poolWithPath(4.0);
    double expectedLength = 2 * PI * 4.0;
    EXPECT_NEAR(expectedLength, poolWithPath.getFerence(), EPS);
}

TEST(PoolTest, TotalCost) {
    double cost = poolTask();
    double expectedCost = (PI * 7.0 * 1000.0) + (2 * PI * 4.0 * 2000.0);
    EXPECT_NEAR(expectedCost, cost, 0.1);
}