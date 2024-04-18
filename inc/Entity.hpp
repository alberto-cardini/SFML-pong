//
// Created by alberto on 4/18/24.
//

#ifndef SFML_PONG_ENTITY_HPP
#define SFML_PONG_ENTITY_HPP

#include "Game.hpp"

class Entity : public sf::Drawable, public sf::Transformable {
public:
    virtual const sf::FloatRect getGlobalBounds() const = 0;
    virtual void move(sf::Time deltaTime);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif //SFML_PONG_ENTITY_HPP
