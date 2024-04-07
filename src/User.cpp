//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

User::User() : platform(sf::Vector2f(5.f, 100.f)) {

    platform.setOrigin(0.f,50.f);
    platform.setPosition(150.f, 150.f);

    /*platform(sf::Quads, 4)
    platform[0].position = sf::Vector2f(0.f, 0.f);
    platform[1].position = sf::Vector2f(5.f, 0.f);
    platform[2].position = sf::Vector2f(5.f, 100.f);
    platform[3].position = sf::Vector2f(0.f, 100.f);

    platform[0].color = sf::Color::Green;
    platform[1].color = sf::Color::Green;
    platform[2].color = sf::Color::Green;
    platform[3].color = sf::Color::Green;
*/
}

sf::Vector2f User::getPos() const { return this->getPosition(); }

sf::Sprite& User::getSprite() { return this->pSprite; }

//sf::VertexArray& User::getShape() { return platform; }
sf::RectangleShape & User::getShape() { return platform; }

void User::setPos(float x, float y) { this->setPosition(x, y); }

void User::setPlatformPos(float x, float y) { this->setPosition(x, y); }

void User::setSpritePos(float x, float y) { pSprite.setPosition(x, y); }