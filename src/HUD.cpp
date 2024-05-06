//
// Created by Alberto Cardini on 18/04/24.
//

#include "HUD.hpp"

HUD::HUD(const sf::Texture& topTex, const sf::Texture& leftTex,
         const sf::Texture& rightTex, const sf::Font& font)
    :  // Texture
      borderTex(new sf::Texture(topTex)),
      leftBorderTex(new sf::Texture(leftTex)),
      rightBorderTex(new sf::Texture(rightTex)),
      // Font
      font(new sf::Font(font)) {
    text.setFont(font);
    text.setPosition(100, 50);
    // Border
    top.setTexture(*borderTex);
    bot.setTexture(*borderTex);
    left.setTexture(*leftBorderTex);
    right.setTexture(*rightBorderTex);

    top.setOrigin(250, 3);
    bot.setOrigin(250, 3);

    right.setOrigin(3, 200);
    left.setOrigin(3, 200);

    top.setPosition(400, 97);
    bot.setPosition(400, 503);

    left.setPosition(147, 294);
    right.setPosition(653, 294);
}

sf::FloatRect HUD::getGlobalBounds(const Side& side) {
    switch (side) {
        case Side::Top:
            return top.getGlobalBounds();

        case Side::Bot:
            return bot.getGlobalBounds();

        case Side::Left:
            return left.getGlobalBounds();

        case Side::Right:
            return right.getGlobalBounds();

        default:
            break;
    }
}