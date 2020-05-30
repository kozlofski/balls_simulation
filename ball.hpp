#pragma once

class Ball
{
private:
    double mass;
    std::vector<double> speed;
    std::vector<double> coords;

public:
    int checkCollisionsWithWalls();
    std::vector<double> checkCollisionsWithBall(Ball);
    void updateSpeed();
    void updateCoords(double timeInterval);
};
