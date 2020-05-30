#pragma once
#include <vector>
#include <ball.hpp>

class Universe
{
public:
    std::vector<Ball> balls;
    double timeInterval = 0.04; // 25 frames per second

    void checkCollisionsWithWalls(std::vector<Ball> balls);
    void checkCollisionsWithOtherBalls(std::vector<Ball> balls);
    void updateSpeeds(std::vector<Ball> balls);
    void updateCoordinates(std::vector<Ball> balls, double timeInterval);
    void saveFrame(std::vector<Ball> balls);
};