//
// Created by Alberto Cardini on 04/04/24.
//
#include "iostream"
#include "Game.hpp"

Ball::Ball() : circle(10.f) {

    setOrigin(10.f, 10.f);
    setPosition(400.f, 300.f);

    velocity.x = -200;
    velocity.y = 100;

}

sf::Vector2f Ball::getVelocity() const { return this->velocity; }

void Ball::setVelocity(sf::Vector2f dir) { this->velocity = dir; }
void Ball::setVelocity(float x, float y) { this->velocity.x = x; this->velocity.y = y; }

void Ball::move(sf::Time dt) {
    circle.move(velocity.x * dt.asSeconds(),velocity.y * dt.asSeconds());
}

