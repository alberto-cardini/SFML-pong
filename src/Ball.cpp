//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

Ball::Ball() : circle(10.f) {

    setOrigin(10.f, 10.f);
    setPosition(400.f, 300.f);

    velocity.x = -200;
    velocity.y = 100;

}

void Ball::move(sf::Time deltaTime) {
    circle.move(velocity.x * deltaTime.asSeconds(),velocity.y * deltaTime.asSeconds());
}

