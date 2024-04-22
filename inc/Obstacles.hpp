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

    const sf::Time& getTimeGain() const { return timeGain; }

    void move(sf::Time deltaTime) override {
        bodySprite.move(0,0);
    };

    //const sf::Text& getTextTimeGain() const { return textTimeGain; }

    //void setTextTimeGain(sf::String& string) { textTimeGain.setString(string); }

private:

    int vertex;
    sf::CircleShape entity;

    //sf::Font asset;
    //sf::Text textTimeGain;
    sf::Time timeGain;

};

#endif  // SFML_PONG_OBSTACLES_HPP
