//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef USER_hpp
#define USER_hpp

#include "Entity.hpp"

class User : public Entity {
public:
    User()
        : Entity("asset/playerTex.png", sf::Vector2f(150.f, 300.f),
                 sf::Vector2f(0, 5), sf::Vector2f(0.f, 50.f)) {}

    void move(sf::Time deltaTime) override {
        bodySprite.move(velocity.x, velocity.y);
    };

    void move(float x, float y) { bodySprite.move(x, y); };

private:
};

#endif