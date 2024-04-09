//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Game.hpp"

class Ball : public sf::Drawable, public sf::Transformable {
public:
    Ball();

    sf::Vector2f getDirection() const ;
    float getSpeed() const;
    sf::CircleShape& getShape();

    void setDirection(sf::Vector2f dir);
    void setDirection(float x, float y);
    void setSpeed(float s);

    void move(sf::Time dt);

    sf::Texture ballTexture;

private:

    float speed;
    sf::Vector2f direction;
    sf::Sprite bSprite;
    sf::CircleShape circle;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &ballTexture;
        target.draw(circle, states);
    }

};

#endif