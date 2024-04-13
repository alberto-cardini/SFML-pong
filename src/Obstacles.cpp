//
// Created by Alberto Cardini on 13/04/24.
//
#include "Obstacles.hpp"

Obstacle::Obstacle() {
    int vertex = 3 + (rand() % 5);
    int offset = 500;

    entity = sf::CircleShape(15 + rand() % 30, vertex);
    setPosition(150 + rand() % 350, 100 + rand() % 350);

}

