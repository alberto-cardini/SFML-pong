//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef GAME_hpp
#define GAME_hpp

#include "SFML/Graphics.hpp"
#include "User.hpp"
#include "Ball.hpp"

class Game{
public:

    Game();

    void render();
    void update();
    void eventManager();
    void run();

    bool hit();
    void move();

private:
    User player;
    Ball ball;

    static float maxHeight;  //counting 0 form the top
    static float minHeight;

    sf::RenderWindow window;
    sf::Text HUD;
    sf::Font font;
    sf::RectangleShape border;
    sf::Clock clock;

    static int score;
};

#endif