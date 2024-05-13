//
// Created by Alberto Cardini on 18/04/24.
//

#include "Entity.hpp"

#include <cmath>

Movable::Movable(const sf::Texture& entityTex, sf::Vector2f pos,
                          sf::Vector2f vel, sf::Vector2f origin)
    : bodyTex(new sf::Texture(entityTex)), velocity(vel) {
    // initialization on the heap to avoid memory leaks.
    // Otherwise, the texture pointer is lost
    bodySprite.setTexture(*bodyTex);
    bodySprite.setOrigin(origin);
    bodySprite.setPosition(pos);
}
Movable::~Movable() { delete bodyTex; }

Immovable::Immovable(const sf::Font& timeFont) : vertex{0},
                                                 font{nullptr} {
    text.setFont(*font);
    text.setCharacterSize(15);
    text.setOutlineThickness(2);

    float x {150.f + rand() % 350};
    float y {100.f + rand() % 350};
    vertex = 3 + (rand() % 4);
    double radius {pow(vertex - 10, 2)};

    entity = sf::CircleShape(radius, vertex);
    entity.setFillColor(
        {sf::Color(10 + rand() % 244,
                         10 + rand() % 244,
                         10 + rand() % 244)});
    // entity.setRotation(rand() % 360);
    //  entity.setOrigin(radius/2, radius/2);
    entity.setPosition(x, y);

    bound = sf::RectangleShape(entity.getGlobalBounds().getSize());
    /*
    bound.setOutlineColor(sf::Color::Red);
    bound.setOutlineThickness(2);
    bound.setFillColor(sf::Color::Transparent);*/
    bound.setPosition(x, y);

    text.setString("+" + std::to_string(vertex));

    textBound = sf::RectangleShape(text.getGlobalBounds().getSize());
    /*    textBound.setOutlineColor(sf::Color::Red);
        textBound.setOutlineThickness(2);
        textBound.setFillColor(sf::Color::Transparent);
        textBound.setOrigin(textBound.getSize().x / 2, textBound.getSize().y /
       2); textBound.setPosition(x + (bound.getSize().x / 2), y +
       (bound.getSize().y / 2));
    */
    text.setOrigin(  textBound.getSize().x / 2,   textBound.getSize().y / 2);
    text.setPosition(x + (bound.getSize().x / 2), y + (bound.getSize().y / 2));
/*
    frameSide top;
    top.frame = sf::RectangleShape(sf::Vector2f{bound.getPosition().x + bound.getSize().x,
                                                     2});
    top.side = Top;
    frame.push_back(top);

    frameSide right;
    right.frame = sf::RectangleShape(sf::Vector2f(2,bound.getPosition().y + 0));
    right.frame = sf::Vector2f(bound.getPosition().x + bound.getSize().x,
                                           bound.getPosition().y + bound.getSize().y);
    right.side = Right;
    frame.push_back(right);

    frameSide bot;
    bot.frame[0].position = sf::Vector2f(bound.getPosition().x + bound.getSize().x,
                                         bound.getPosition().y + bound.getSize().y);
    bot.frame[1].position = sf::Vector2f(bound.getPosition().x + 0,
                                         bound.getPosition().y + bound.getSize().y);
    bot.side = Bot;
    frame.push_back(bot);

    frameSide left;
    left.frame[0].position = sf::Vector2f(bound.getPosition().x + 0,
                                          bound.getPosition().y + bound.getSize().y);
    left.frame[1].position = sf::Vector2f(bound.getPosition().x + 0,
                                          bound.getPosition().y + 0);
    left.side = Left;
    frame.push_back(left);
*/
}

std::vector<struct frameSide> Immovable::getFrame() const{

    //std::vector<struct frameSide> frame;

    //return frame;
}