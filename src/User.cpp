//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

User::User() : platform(sf::Vector2f(5.f, 100.f)) {
    setOrigin(0.f,50.f);
    setPosition(150.f, 300.f);
    platform.setFillColor(sf::Color::Green);
}
