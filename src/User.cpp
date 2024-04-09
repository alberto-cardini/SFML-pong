//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

User::User() : platform(sf::Vector2f(5.f, 100.f)) {

    platform.setOrigin(0.f,50.f);
    platform.setPosition(150.f, 300.f);
    platform.setFillColor(sf::Color::Green);

}

sf::RectangleShape& User::getShape() { return platform; }

void User::setPlatformPos(float x, float y) { this->setPosition(x, y); }

