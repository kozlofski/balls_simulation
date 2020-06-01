#pragma once

#include <vector>

enum class Wall {
    X_Pos,
    X_neg,
    Y_Pos,
    Y_Neg,
    Z_Pos,
    Z_Neg
};

class Universe {
private:
    std::vector<Ball> balls;
    double dt = 0.04;  // time interval - 25 frames per second
    double boxSize = 1.0;
    int currentFrame = 0;

public:
    void saveFrame(std::vector<Ball> balls);
    void evolution(const int interations);

private:
    void round();
    Wall detectCollisionsWithWalls(const Ball& ball);
    void bounceFromWall(Ball& ball, const Wall& wall);
    std::vector<Ball> checkCollisionsWithOtherBalls(const Ball& ball, const std::vector<Ball>& balls);
    void bounceFromBall(Ball& ball, const std::vector<Ball>& ballsCollided);
    // void updateSpeeds(Ball & ball);
    void moveBalls(std::vector<Ball> balls, double timeInterval);

    Universe();
    ~Universe();
};