#include "universe.hpp"

#include "ball.hpp"

void Universe::saveFrame(std::vector<Ball> balls) {
}

void Universe::evolution(const int iterations) {
    for (int i = 0; i < iterations; i++) {
        round();
    }
}

void Universe::round() {
    for (auto& ball : balls) {
        std::vector<Wall> wallsHit = detectCollisionsWithWalls(ball);
        bounceFromWall(ball, wallsHit);
    }
}

std::vector<Wall> Universe::detectCollisionsWithWalls(Ball& ball) {
    std::vector<Wall> wallsHit;  //maybe std::array<Ball> wolud me more efficient
    wallsHit.reserve(3);
    if (ball.getCoords().x + ball.getRadius() >= 1.0) {
        wallsHit.emplace_back(Wall::X_Pos);
    }
    if (ball.getCoords().y + ball.getRadius() >= 1.0) {
        wallsHit.emplace_back(Wall::Y_Pos);
    }
    if (ball.getCoords().z + ball.getRadius() >= 1.0) {
        wallsHit.emplace_back(Wall::Z_Pos);
    }
    if (ball.getCoords().x + ball.getRadius() <= 1.0) {
        wallsHit.emplace_back(Wall::X_Neg);
    }
    if (ball.getCoords().y + ball.getRadius() <= 1.0) {
        wallsHit.emplace_back(Wall::Y_Neg);
    }
    if (ball.getCoords().z + ball.getRadius() <= 1.0) {
        wallsHit.emplace_back(Wall::Z_Neg);
    }

    return wallsHit;
}

void Universe::bounceFromWall(Ball& ball, const std::vector<Wall>& wallsHit) {
    for (const auto& wall : wallsHit) {
        ball.bounceFromWall(wall);
    }
}

void detectCollisionsWithBalls(std::vector<Ball>& balls) {
    for (auto i = balls.begin(); i < balls.end() - 1; i++) {
        for (auto j = i + 1; i < balls.end(); j++) {
            if (ball[i].hasCollidedWith(ball[j])) {
                ball[i].bounceFromBall(ball[j]);  // implementation is a two way collistion
                // ball[j].bounceFromBall(ball[i]);
            }
        }
    }
}

std::vector<Ball> Universe::checkCollisionsWithOtherBalls(const Ball& ball, const std::vector<Ball>& balls) {
    std::vector<Ball> ballsHit;  //maybe std::array<Ball> wolud me more efficient
    ballsHit.reserve(3);         //arbitrary value; must be discussed how many balls can collide in one moment
}

// void Universe::bounceFromBall(Ball& ball, const std::vector<Ball>& ballsCollided) {
// }
// void updateSpeeds(Ball & ball);
void Universe::moveBalls(std::vector<Ball> balls, double timeInterval) {
}

Universe::Universe() {
}

Universe::~Universe() {}
}
;