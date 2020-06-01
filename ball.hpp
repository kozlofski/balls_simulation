#pragma once

#include <vector>

struct Coords {
    double x, y, z;
};

struct Speed {
    double x, y, z;
};

class Ball {
private:
    double mass;
    double radius;
    Speed speed;
    Coords coords;

public:
    Ball() {}
    ~Ball() {}

    void updateCoords(double timeInterval);
    int checkCollisionsWithWalls();
    void bounceFromWall(const Wall& wallHit);
    bool hasCollidedWith(Ball& ball);
    std::vector<double> checkCollisionsWithBall(Ball);
    void bounceFromBall(Ball& otherBall);

    void setSpeed(const Coords& coords);
    Speed getSpeed();
    void setCoords(const Speed& speed);
    Coords getCoords();
    double getRadius();

    void print();

    // Ball& operator<<{};
};
