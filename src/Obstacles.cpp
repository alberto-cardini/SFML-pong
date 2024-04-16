//
// Created by Alberto Cardini on 13/04/24.
//
#include "Obstacles.hpp"

Obstacle::Obstacle() {
    int vertex = 3 + (rand() % 5);

    entity = sf::CircleShape(15 + rand() % 30, vertex);
    entity.setFillColor(sf::Color(
            10 + rand() % 244,
            10 + rand() % 244,
            10 + rand() % 244));
    setPosition(150 + rand() % 350, 100 + rand() % 350);

}
