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

    void setVelocity(int x, int y) { velocity.x = x; velocity.y = y; }

    const sf::Vector2i& getVelocity() const { return velocity; }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected:

    sf::Vector2i velocity;

};

#endif //SFML_PONG_ENTITY_HPP
