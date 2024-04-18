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
#include "Entity.hpp"

class User : public Entity {
public:
    User();

    const sf::FloatRect getGlobalBounds() const override {
        return getTransform().transformRect(platform.getGlobalBounds());
    }
    void move(int x, int y) override;
private:

    sf::RectangleShape platform;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        target.draw(platform, states);
    }

};

#endif