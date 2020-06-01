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
    std::vector<double> checkCollisionsWithBall(Ball);

    void set_speed(const Coords& coords);
    Speed get_speed();
    void set_coords(const Speed& speed);
    Coords get_coords();

    void print();

    // Ball& operator<<{};
};
