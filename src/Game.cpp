//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

#include <iostream>
AssetManager* Game::assetManager = new AssetManager();
sf::Time Game::spawnTime = sf::seconds(5);
const float Game::MAX_HEIGHT = 150;  // counting 0 form the top
const float Game::MIN_HEIGHT = 450;

Game::Game()
    :  // Entities
      player(new User(AssetManager::getTexture("playerTex"))),
      ball(new Ball(AssetManager::getTexture("ballTex"))),
      // HUD
      hud(new HUD(AssetManager::getTexture("borderTex"),
                  AssetManager::getTexture("leftBorderTex"),
                  AssetManager::getTexture("rightBorderTex"),
                  AssetManager::getFont("OpenSans-Regular"))),
      // Window
      window(new sf::RenderWindow(sf::VideoMode(800, 600), "Pong",
                                  sf::Style::Close)),

      // Game State
      gamePaused(false),
      gameOver(false),
      // Time
      dtClock(sf::Clock()),
      gameClock(sf::Clock()),
      spawnClock(sf::Clock()),
      gameTime(sf::seconds(20)) {
    window->setFramerateLimit(60);
}

void Game::updateHUD() {
    auto string =
        "TIME LEFT: " +
        std::to_string(static_cast<int>(
            gameTime.asSeconds() - gameClock.getElapsedTime().asSeconds())) +
        " sec.";
    hud->setString(string);
}

void Game::render() {
    window->clear();
    window->draw(*hud);
    window->draw(*ball);
    window->draw(*player);
    for (objType::Immovable* n : obs) {
        window->draw(*n);
    }
    window->display();
}

void Game::render_menu() { std::cout << gamePaused << std::endl; }

void Game::update() {
    if (gameClock.getElapsedTime().asSeconds() < gameTime.asSeconds() &&
        !gamePaused) {
        updateHUD();
        deltaTime = dtClock.restart();
        ball->move(deltaTime);
        hit();
        static long seed;
        seed = std::time(nullptr) + seed;
        srand(seed);
        if (static_cast<int>(spawnClock.getElapsedTime().asSeconds() -
                             spawnTime.asSeconds()) == 0) {
            spawnClock.restart();
            spawnObs();
        }
    } else if (gameClock.getElapsedTime().asSeconds() > gameTime.asSeconds() ||
               gamePaused) {
        gameClock.restart();
        restart();
    } else {
    }
}

void Game::restart() {
    gameTime = sf::seconds(20);
    gameClock.restart();
    ball->setPosition(400, 300);
    obs.clear();
}

void Game::manageEvent() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (player->getPosition().y < MIN_HEIGHT) {
            player->setVelocity(0, 5);
            player->move(deltaTime);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (player->getPosition().y > MAX_HEIGHT) {
            std::cout << "y: " << player->getPosition().y << std::endl;
            player->setVelocity(0, -5);
            player->move(deltaTime);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) gamePaused = true;

    while (gamePaused) {
        render_menu();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) gamePaused = false;
    }

    sf::Event event{};
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;

            default:
                break;
        }
    }
}

void Game::run() {
    while (window->isOpen()) {
        manageEvent();
        update();
        render();
    }
    delete assetManager;
}

void Game::spawnObs() {
    auto* newObs =
        new objType::Immovable(AssetManager::getFont("OpenSans-Regular"));
    obs.push_back(newObs);
}

void Game::hit() {  // remember that the y-axis is flipped, down is positive and
                    // up negative. x-axis is OK
    for (int i = 0; i < obs.size(); i++) {
        if (ball->getGlobalBounds().intersects(obs[i]->getGlobalBounds())) {
            ball->setVelocity(ball->getVelocity().x * (-1),
                              ball->getVelocity().y * (1));
            obs.erase(obs.end() - (obs.size() - i));
            gameTime += sf::seconds(obs[i]->getVertex());
        }
    }

    if (ball->getGlobalBounds().intersects(player->getGlobalBounds())) {
        ball->setVelocity(ball->getVelocity().x * (-1),
                          ball->getVelocity().y * (1));
    }

    if (ball->getGlobalBounds().intersects(hud->getGlobalBounds(Top))) {
        ball->setVelocity(ball->getVelocity().x * (1),
                          ball->getVelocity().y * (-1));
    }

    if (ball->getGlobalBounds().intersects(hud->getGlobalBounds(Bot))) {
        ball->setVelocity(ball->getVelocity().x * (1),
                          ball->getVelocity().y * (-1));
    }

    if (ball->getGlobalBounds().intersects(hud->getGlobalBounds(Left))) {
        ball->setVelocity(ball->getVelocity().x * (-1),
                          ball->getVelocity().y * (1));
        gameTime -= sf::seconds(3);
    }

    if (ball->getGlobalBounds().intersects(hud->getGlobalBounds(Right))) {
        ball->setVelocity(ball->getVelocity().x * (-1),
                          ball->getVelocity().y * (1));
    }
}
