//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

Ball::Ball() {

    // initialization on the heap to avoid memory leaks.
    // Otherwise, the texture pointer is lost
    bodyTex = new sf::Texture;
    if (!bodyTex->loadFromFile("asset/ballTex.png")) {
        perror("Wrong file");
    }
    bodySprite.setTexture(*bodyTex);
    setOrigin(10.f, 10.f);
    setPosition(400.f, 300.f);

    velocity.x = -200;
    velocity.y = 100;

}

void Ball::move(sf::Time dt) {
    bodySprite.move(velocity.x * dt.asSeconds(), velocity.y * dt.asSeconds());
}

