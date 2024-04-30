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
#include "HUD.hpp"

class Game {
public:
    Game();

    void render();
    void updateHUD();
    void render_menu();

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
    HUD *hud;

    static float maxHeight;  // counting 0 form the top
    static float minHeight;
    static sf::Time spawnTime;
    // Window
    sf::RenderWindow* window;
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