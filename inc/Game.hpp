//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef GAME_hpp
#define GAME_hpp

#include "SFML/Graphics.hpp"
#include "Ball.hpp"
#include "Obstacles.hpp"
#include "User.hpp"
#include "Entity.hpp"

class Game {
public:
    Game();

    void render();
    void renderHUD();
    void update();
    void manageEvent();
    void run();
    void restart();

    void hit();
    void spawnObs();

private:
    Entity* player;
    Entity* ball;
    std::vector<Entity*> obs;

    static float maxHeight;  // counting 0 form the top
    static float minHeight;
    static sf::Time spawnTime;
    // Window
    sf::RenderWindow* window;
    // HUD
    sf::Text HUD;
    sf::Font font;
    // Border
    sf::RectangleShape top;
    sf::RectangleShape bot;
    sf::RectangleShape right;
    sf::RectangleShape left;
    // Time capture
    sf::Clock dtClock;
    sf::Clock gameClock;
    sf::Clock spawnClock;
    sf::Time deltaTime;
    sf::Time gameTime;
    //Game State
    bool gamePaused;
    bool gameOver;
};

#endif