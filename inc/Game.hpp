//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef GAME_hpp
#define GAME_hpp

#include "SFML/Graphics.hpp"
#include "User.hpp"
#include "Ball.hpp"
#include "Obstacles.hpp"

class Game{
public:

    Game();

    void render();
    void renderHUD();
    void update();
    void eventManager();
    void run();
    void restart();

    sf::Vector2f getVector(const Obstacle& obs) const;
    void hit();

private:

    User player;
    Ball ball;
    std::vector<Obstacle> obs;

    static float maxHeight;  //counting 0 form the top
    static float minHeight;
    static int score;

    //Window
    sf::RenderWindow window;
    //HUD
    sf::Text scoreText;
    sf::Font font;
    //Border
    sf::RectangleShape top;
    sf::RectangleShape bot;
    sf::RectangleShape right;
    sf::RectangleShape left;
    //Time capture
    sf::Clock clock;
    sf::Time deltaTime;
};

#endif