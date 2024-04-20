//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

Ball::Ball() {

    if(!ballTex.loadFromFile("asset/ballTex.png")){
        perror("Wrong file");
    }
    ballSprite.setTexture(ballTex);
    setOrigin(10.f, 10.f);
    setPosition(400.f, 300.f);

    velocity.x = -200;
    velocity.y = 100;

}

void Ball::move(sf::Time deltaTime) {
    ballSprite.move(velocity.x * deltaTime.asSeconds(),velocity.y * deltaTime.asSeconds());
}

