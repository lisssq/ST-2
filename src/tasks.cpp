// Copyright 2026 UNN-CS Team
#include "tasks.h"
#include <cmath>
#include "circle.h"

const double EARTH_RADIUS_KM = 6378.1;
const double EARTH_RADIUS_M = EARTH_RADIUS_KM * 1000;
const double PI = 3.14159265358979323846;

double earthAndRopeTask() {
    Circle earth(EARTH_RADIUS_M);
    double oldFerence = earth.getFerence();
    double newFerence = oldFerence + 1.0;

    earth.setFerence(newFerence);
    double newRadius = earth.getRadius();

    return newRadius - EARTH_RADIUS_M;
}

double poolTask() {
    double poolRadius = 3.0;
    double pathWidth = 1.0;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double concreteCost = pathArea * 1000.0;
    double fenceCost = fenceLength * 2000.0;

    return concreteCost + fenceCost;
}
