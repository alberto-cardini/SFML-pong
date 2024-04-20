//
// Created by Alberto Cardini on 18/04/24.
//

#ifndef SFML_PONG_HUD_HPP
#define SFML_PONG_HUD_HPP

#include "Game.hpp"

class HUD : public sf::Drawable, sf::Transformable {
public:

    HUD();



private:



protected:

    sf::Font font;
    sf::Text text;
};

#endif  // SFML_PONG_HUD_HPP
