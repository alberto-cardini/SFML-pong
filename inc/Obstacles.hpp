//
// Created by Alberto Cardini on 13/04/24.
//

#ifndef SFML_PONG_OBSTACLES_HPP
#define SFML_PONG_OBSTACLES_HPP

#include "Entity.hpp"

class Obstacle : public Entity {
public:
    Obstacle();

    int getVertex() const { return vertex; }

    const sf::FloatRect getGlobalBounds() {
        return getTransform().transformRect(entity.getGlobalBounds());
    };

    void move(const sf::Time& deltaTime) override {
        bodySprite.move(0,0);
    };

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();
        target.draw(entity, states);
    }

    int vertex;
    sf::CircleShape entity;
};

#endif  // SFML_PONG_OBSTACLES_HPP
