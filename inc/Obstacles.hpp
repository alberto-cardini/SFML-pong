//
// Created by Alberto Cardini on 13/04/24.
//

#ifndef SFML_PONG_OBSTACLES_HPP
#define SFML_PONG_OBSTACLES_HPP

#include "SFML/Graphics.hpp"
#include "Entity.hpp"

class Obstacle : public Entity {
public:
    Obstacle();

    const sf::FloatRect getGlobalBounds() const override {
        return getTransform().transformRect(entity.getGlobalBounds());
    }

    int getVertex() const { return vertex; }
    const sf::Time& getTimeGain() const { return timeGain; }
    //const sf::Text& getTextTimeGain() const { return textTimeGain; }

    //void setTextTimeGain(sf::String& string) { textTimeGain.setString(string); }

private:

    int vertex;
    sf::CircleShape entity;

    //sf::Font font;
    //sf::Text textTimeGain;
    sf::Time timeGain;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(entity, states);
    }

};

#endif  // SFML_PONG_OBSTACLES_HPP
