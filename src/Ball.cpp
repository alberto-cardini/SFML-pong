//
// Created by Alberto Cardini on 04/04/24.
//
#include "iostream"
#include "Game.hpp"

Ball::Ball() : circle(10.f), speed(5), bSprite(bTexture) {

    circle.setOrigin(10.f, 10.f);
    circle.setPosition(400.f, 300.f);

    direction.x = -1;
    direction.y = 1;
}

sf::Vector2f Ball::getDirection() const { return this->direction; }
sf::CircleShape& Ball::getShape() { return this->circle; }

float Ball::getSpeed() const { return this->speed; }

void Ball::setDirection(sf::Vector2f dir) { this->direction = dir; }
void Ball::setDirection(float x, float y) { this->direction.x = x; this->direction.y = y; }

void Ball::setSpeed(float s) { this->speed = s; }

void Ball::move() {
    circle.move(direction.x,0);
}