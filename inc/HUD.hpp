//
// Created by Alberto Cardini on 18/04/24.
//

#ifndef SFML_PONG_HUD_HPP
#define SFML_PONG_HUD_HPP

#include "SFML/Graphics.hpp"

enum Side {Top, Bot, Left, Right};

class HUD : public sf::Drawable, public sf::Transformable {
public:
    HUD();

    void setString(const std::string& score) { text.setString(score); }

    const sf::FloatRect getGlobalBounds(const Side& side);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(text, states);
        target.draw(top, states);
        target.draw(bot, states);
        target.draw(left, states);
        target.draw(right, states);
    }

protected:
    sf::Font font;
    sf::Text text;

    // Border
    sf::Sprite top;
    sf::Sprite bot;
    sf::Sprite right;
    sf::Sprite left;

    sf::Texture* borderTex;
    sf::Texture* leftBorderTex;
    sf::Texture* rightBorderTex;
};

#endif  // SFML_PONG_HUD_HPP
