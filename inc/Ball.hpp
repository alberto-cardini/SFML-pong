//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Entity.hpp"

class Ball : public objType::Movable {
public:
    explicit Ball(const sf::Texture& ballTex)
        : objType::Movable(ballTex, sf::Vector2f(400.f, 300.f),
                 sf::Vector2f(-200, 100), sf::Vector2f(10.f, 10.f)) {}

    void move(const sf::Time& dt) override {
        bodySprite.move(velocity.x * dt.asSeconds(),
                        velocity.y * dt.asSeconds());
    };

private:
    // TODO asser manager
};

#endif