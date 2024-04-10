//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Game.hpp"

class Ball : public sf::Drawable, public sf::Transformable {
public:

    Ball();

    sf::Vector2f getVelocity() const ;

    void setPosition(float x, float y) { circle.setPosition(x,y); }

    const sf::FloatRect getGlobalBounds() const {
        return getTransform().transformRect(circle.getGlobalBounds());
    }

    void setVelocity(sf::Vector2f dir);
    void setVelocity(float x, float y);

    void move(sf::Time dt);

private:

    sf::Vector2f velocity;
    sf::CircleShape circle;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(circle, states);
    }

};

#endif