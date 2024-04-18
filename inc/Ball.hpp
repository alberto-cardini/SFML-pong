//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include "Entity.hpp"

class Ball : public Entity {
public:
    Ball();

    sf::Vector2f getVelocity() const;

    sf::Vector2f getPosition() { return circle.getPosition(); }
    void setPosition(float x, float y) { circle.setPosition(x, y); }

    const sf::FloatRect getGlobalBounds() const override {
        return getTransform().transformRect(circle.getGlobalBounds());
    }

    void setVelocity(sf::Vector2f dir);
    void setVelocity(float x, float y);

    void move(sf::Time dt);

private:
    sf::Vector2f velocity;
    sf::CircleShape circle;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        target.draw(circle, states);
    }
};

#endif