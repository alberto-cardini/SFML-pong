//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Entity.hpp"

class Ball : public Entity {
public:

    Ball();

    sf::Vector2f getPosition() { return circle.getPosition(); }
    void setPosition(float x, float y) { circle.setPosition(x, y); }

    const sf::FloatRect getGlobalBounds() const {
        return getTransform().transformRect(circle.getGlobalBounds());
    }

    void move(sf::Time dt);

private:

    sf::CircleShape circle;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(circle, states);
    }
};

#endif