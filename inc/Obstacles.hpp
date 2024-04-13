//
// Created by Alberto Cardini on 13/04/24.
//

#ifndef SFML_PONG_OBSTACLES_HPP
#define SFML_PONG_OBSTACLES_HPP

#include "SFML/Graphics.hpp"

class Obstacle : public sf::Drawable, sf::Transformable {
public:

    Obstacle();

    const sf::FloatRect getGlobalBounds() const {
        return getTransform().transformRect(entity.getGlobalBounds());
    }

private:

    sf::CircleShape entity;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(entity, states);
    }

};

#endif //SFML_PONG_OBSTACLES_HPP
