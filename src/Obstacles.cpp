//
// Created by Alberto Cardini on 13/04/24.
//
#include "Obstacles.hpp"
#include <cmath>

Obstacle::Obstacle() {

    velocity.x = 0;
    velocity.y = 0;

    int x = 150 + rand() % 350;
    int y = 100 + rand() % 350;

    vertex = 3 + (rand() % 4);
    entity = sf::CircleShape(pow(vertex - 10, 2), vertex);
    entity.setFillColor(
        sf::Color(10 + rand() % 244, 10 + rand() % 244, 10 + rand() % 244));
    entity.setPosition(x, y);

}
