//
// Created by Alberto Cardini on 18/04/24.
//

#include "Entity.hpp"

Entity::Entity() = default;

Entity::Entity(const std::string& texturePath, sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f origin) {
    // initialization on the heap to avoid memory leaks.
    // Otherwise, the texture pointer is lost
    bodyTex = new sf::Texture;
    if (!bodyTex->loadFromFile(texturePath)) {
        perror("Wrong path or working dir");
    }
    bodySprite.setTexture(*bodyTex);

    velocity = vel;
    bodySprite.setOrigin(origin);
    bodySprite.setPosition(pos);
}