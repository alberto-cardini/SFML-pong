//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef USER_hpp
#define USER_hpp

#include "Game.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

class User : public sf::Drawable, public sf::Transformable {
public:
    User();

    const sf::FloatRect getGlobalBounds() const {
        return getTransform().transformRect(platform.getGlobalBounds());
    }

private:

    sf::RectangleShape platform;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(platform, states);
    }

};

#endif