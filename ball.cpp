#include "ball.hpp"

#include <cmath>

#include "universe.hpp"

void Ball::setSpeed(const Coords& coords) {
    this->coords = coords;
}

Speed Ball::getSpeed() {
    return speed;
}

void Ball::setCoords(const Speed& speed) {
    this->speed = speed;
}

Coords Ball::getCoords() {
    return coords;
}

double Ball::getRadius() {
    return radius;
}

void Ball::bounceFromWall(const Wall& wallHit) {
    if (wallHit == Wall::X_Pos || wallHit == Wall::X_Neg) {
        speed.x *= -1;
    } else if (wallHit == Wall::Y_Pos || wallHit == Wall::Y_Neg) {
        speed.y *= -1;
    } else if (wallHit == Wall::Z_Pos || wallHit == Wall::Z_Neg) {
        speed.z *= -1;
    }
}

bool Ball::hasCollidedWith(Ball& otherBall) {
    Speed otherBallSpeed = otherBall.getSpeed();
    double distanceBetweenBalls = std::sqrt(pow(otherBallSpeed.x - this->speed.x, 2) +
                                            pow(otherBallSpeed.y - this->speed.y, 2) + pow(otherBallSpeed.z - this->speed.z, 2));
    if (distanceBetweenBalls <= (otherBall.getRadius() + this->getRadius())) {
        return true;
    }
    return false;
}

void bounceFromBall(Ball otherBall) {
    // place for that magic formula modifying ball's speeds
}