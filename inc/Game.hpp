//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef GAME_hpp
#define GAME_hpp

#include "Ball.hpp"
#include "Entity.hpp"
#include "HUD.hpp"
#include "SFML/Graphics.hpp"
#include "User.hpp"
#include "AssetManager.hpp"

class Game {
public:
    Game();

    void render();
    void updateHUD();

    void update();
    void manageEvent();
    void run();
    void restart();

    void hit();
    void spawnObs();

private:
    objType::Movable* player;
    objType::Movable* ball;
    std::vector<objType::Immovable*> obs;
    HUD* hud;

    const static float MAX_HEIGHT;  // counting 0 form the top
    const static float MIN_HEIGHT;
    static sf::Time spawnTime;
    // Window
    sf::RenderWindow* window;
    // Asset Manager
    static AssetManager* assetManager;
    //  Time capture
    sf::Clock dtClock;
    sf::Clock gameClock;
    sf::Clock spawnClock;
    sf::Time deltaTime;
    sf::Time gameTime;
    // Game State
    bool gamePaused;
    bool gameOver;
};

#endif