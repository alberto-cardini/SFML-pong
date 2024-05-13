//
// Created by alberto on 4/18/24.
//

#ifndef SFML_PONG_ENTITY_HPP
#define SFML_PONG_ENTITY_HPP

#include "SFML/Graphics.hpp"
#include "HUD.hpp"
//enum FrameSide { Top, Bot, Left, Right };

class Movable : public sf::Drawable, public sf::Transformable {
public:
    Movable() : velocity{0, 0}, bodyTex{nullptr} {}

    Movable(const sf::Texture& entityTex, sf::Vector2f pos, sf::Vector2f vel,
            sf::Vector2f origin);

    ~Movable() override;

    const sf::FloatRect getGlobalBounds() {
        return getTransform().transformRect(bodySprite.getGlobalBounds());
    }

    virtual void move(const sf::Time& deltaTime) = 0;

    void setVelocity(float x, float y) {
        velocity.x = x;
        velocity.y = y;
    }

    void setVelocity(sf::Vector2f input) { velocity = input; }

    sf::Vector2f& getVelocity() { return velocity; }

    const sf::Vector2f& getPosition() const { return bodySprite.getPosition(); }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = bodyTex;
        target.draw(bodySprite, states);
    }

protected:
    sf::Vector2f        velocity;
    sf::Sprite          bodySprite;
    const sf::Texture*  bodyTex;
};

struct frameSide {
    sf::RectangleShape frame;
    Side side;
};

typedef struct frameSide frameSide;

class Immovable : public sf::Drawable {
public:
    Immovable() : vertex{0}, font{nullptr} {}

    explicit Immovable(const sf::Font& timeFont);

    int getVertex() const { return vertex; }

    sf::FloatRect getGlobalBounds() { return entity.getGlobalBounds(); }

    std::vector<struct frameSide> getFrame() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(entity, states);
        target.draw(text, states);
        for (int i = 0; i < 3; ++i) {
            target.draw(frame[i].frame, states);
        }
        // target.draw(textBound, states);
    }

    int                         vertex;
    std::vector<frameSide>      frame;
    sf::RectangleShape          bound,
                                textBound;
    sf::Text                    text;
    sf::Font*                   font;
    sf::CircleShape             entity;
};

#endif  // SFML_PONG_ENTITY_HPP
