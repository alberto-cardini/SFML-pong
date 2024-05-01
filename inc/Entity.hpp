//
// Created by alberto on 4/18/24.
//

#ifndef SFML_PONG_ENTITY_HPP
#define SFML_PONG_ENTITY_HPP

#include "SFML/Graphics.hpp"

namespace objType {

class Movable : public sf::Drawable, public sf::Transformable {
public:
    Movable();
    Movable(const sf::Texture* entityTex, sf::Vector2f pos, sf::Vector2f vel,
            sf::Vector2f origin);

    const sf::FloatRect getGlobalBounds() {
        return getTransform().transformRect(bodySprite.getGlobalBounds());
    };

    virtual void move(const sf::Time& deltaTime) = 0;

    void setVelocity(float x, float y) {
        velocity.x = x;
        velocity.y = y;
    }

    const sf::Vector2f& getVelocity() const { return velocity; }

    sf::Vector2f getPosition() { return bodySprite.getPosition(); }

    void setPosition(float x, float y) { bodySprite.setPosition(x, y); }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = bodyTex;
        target.draw(bodySprite, states);
    }

protected:
    sf::Vector2f velocity;
    sf::Sprite bodySprite;
    const sf::Texture* bodyTex;
};

class Immovable : public sf::Drawable, public sf::Transformable {
public:
    Immovable();

    int getVertex() const { return vertex; }

    const sf::FloatRect getGlobalBounds() {
        return getTransform().transformRect(entity.getGlobalBounds());
    };

private:
    virtual void draw(sf::RenderTarget& target,
                      sf::RenderStates states) const override {
        states.transform *= getTransform();
        target.draw(entity, states);
        target.draw(text, states);
        //target.draw(bound, states);
        //target.draw(textBound, states);
    }

    int vertex;
    sf::RectangleShape bound;
    sf::RectangleShape textBound;
    sf::Text text;
    sf::Font* font;
    sf::CircleShape entity;
};
}  // namespace objType

#endif  // SFML_PONG_ENTITY_HPP
