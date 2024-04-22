//
// Created by alberto on 4/18/24.
//

#ifndef SFML_PONG_ENTITY_HPP
#define SFML_PONG_ENTITY_HPP

#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable {

public:

    const sf::FloatRect getGlobalBounds() {
        return getTransform().transformRect(bodySprite.getGlobalBounds());
    };

    virtual void move(sf::Time deltaTime) = 0;

    void setVelocity(int x, int y) { velocity.x = x; velocity.y = y; }

    const sf::Vector2i& getVelocity() const { return velocity; }

    sf::Vector2f getPosition() { return bodySprite.getPosition(); }

    void setPosition(float x, float y) { bodySprite.setPosition(x, y); }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = bodyTex;
        target.draw(bodySprite, states);
    }

protected:

    sf::Vector2i velocity;
    sf::Sprite bodySprite;
    sf::Texture* bodyTex;

};

#endif //SFML_PONG_ENTITY_HPP
