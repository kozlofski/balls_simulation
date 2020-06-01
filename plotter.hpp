#pragma once

#include "./inc/matplotlibcpp.h"

class Plotter {
private:
public:
    void plotBalls2D(std::vector<Ball> balls);
    void makeAnimation(double delay, bool loop, std::string input, std::string output);
};
