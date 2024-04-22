//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

User::User() {

    bodyTex = new sf::Texture();
    if (!bodyTex->loadFromFile("asset/playerTex.png")) {
        perror("Wrong directory");
    }
    setOrigin(0.f,50.f);
    setPosition(150.f, 300.f);

    velocity.x = 0;
    velocity.y = 5;
}

void User::move(sf::Time deltaTime) {
    bodySprite.move(0,5);
}