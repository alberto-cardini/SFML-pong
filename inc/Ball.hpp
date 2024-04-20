//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Entity.hpp"

class Ball : public Entity {
public:

    Ball();

    sf::Vector2f getPosition() { return ballSprite.getPosition(); }
    void setPosition(float x, float y) { ballSprite.setPosition(x, y); }

    const sf::FloatRect getGlobalBounds() const {
        return getTransform().transformRect(ballSprite.getGlobalBounds());
    }

    void setVelocity(sf::Vector2f dir);
    void setVelocity(float x, float y);

    void move(sf::Time dt);

private:
    sf::Vector2f velocity;
    sf::Sprite ballSprite;
    sf::Texture ballTex;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &ballTex;
        target.draw(ballSprite, states);
    }
};

#endif