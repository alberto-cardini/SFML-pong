//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef USER_hpp
#define USER_hpp

#include "Entity.hpp"

class User : public Movable {
public:
    explicit User(const sf::Texture& playerTex)
        : Movable{playerTex,
                  {150.f, 300.f},
                  {0, 5},
                  {0.f, 50.f}} {}

    void move(const sf::Time& deltaTime) override {
        bodySprite.move(velocity.x,
                        velocity.y);
    };
};

#endif