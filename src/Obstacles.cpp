//
// Created by Alberto Cardini on 13/04/24.
//
#include "Obstacles.hpp"
#include <cmath>

Obstacle::Obstacle() {
    int x = 150 + rand() % 350;
    int y = 100 + rand() % 350;

    vertex = 3 + (rand() % 4);
    timeGain = sf::seconds(vertex);
    entity = sf::CircleShape(pow(vertex - 10, 2), vertex);
    entity.setFillColor(
        sf::Color(10 + rand() % 244, 10 + rand() % 244, 10 + rand() % 244));
    setPosition(x, y);

    /*
    if (!font.loadFromFile("font/OpenSans-Regular.ttf"))
        perror("Wrong working directory");

        sf::String string = std::to_string(vertex) + " sec";
        textTimeGain = sf::Text(string, font, 15);
        textTimeGain.setPosition(x, y);*/
}
