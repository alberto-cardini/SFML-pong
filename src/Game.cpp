//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"

#include <iostream>

sf::Time Game::spawnTime = sf::seconds(5);
float Game::maxHeight = 150;  // counting 0 form the top
float Game::minHeight = 450;

Game::Game()
    :
      //Entities
      player(new User()),
      ball(new Ball()),
      //Time
      dtClock(sf::Clock()),
      gameClock(sf::Clock()),
      spawnClock(sf::Clock()),
      gameTime(sf::seconds(20)) {

    window =
        new sf::RenderWindow(sf::VideoMode(800, 600), "Pong", sf::Style::Close);
    window->setFramerateLimit(60);

    // HUD
    if (!font.loadFromFile("asset/OpenSans-Regular.ttf")) {
        perror("Wrong working directory");
    }

    if (!borderTex.loadFromFile("asset/borderTex.png")) {
        perror("Wrong working directory");
    }
    if (!leftBorderTex.loadFromFile("asset/leftBorderTex.png")) {
        perror("Wrong working directory");
    }
    if (!rightBorderTex.loadFromFile("asset/rightBorderTex.png")) {
        perror("Wrong working directory");
    }
    HUD.setFont(font);
    HUD.setPosition(100, 50);

    // Border
    top.setTexture(borderTex);
    bot.setTexture(borderTex);
    left.setTexture(leftBorderTex);
    right.setTexture(rightBorderTex);

    top.setOrigin(250, 3);
    bot.setOrigin(250, 3);

    right.setOrigin(3, 200);
    left.setOrigin(3, 200);

    top.setPosition(400, 97);
    bot.setPosition(400, 503);

    left.setPosition(147, 294);
    right.setPosition(653, 294);
    // Game State
    gamePaused = false;
    gameOver = false;
}

void Game::renderHUD() {
    sf::String string =
        "TIME LEFT: " +
        std::to_string(static_cast<int>(
            gameTime.asSeconds() - gameClock.getElapsedTime().asSeconds())) +
        " sec.";
    HUD.setString(string);
    window->draw(top);
    window->draw(bot);
    window->draw(right);
    window->draw(left);
}

void Game::render() {
    window->clear();
    renderHUD();
    window->draw(HUD);
    window->draw(*ball);
    window->draw(*player);
    for (const Entity* n : obs) {
        window->draw(*n);
        // window.draw(n.timeGain);
    }
    window->display();
}

void Game::render_menu() { std::cout << gamePaused << std::endl; }

void Game::update() {
    if (gameClock.getElapsedTime().asSeconds() < gameTime.asSeconds() &&
        !gamePaused) {
        deltaTime = dtClock.restart();
        ball->move(deltaTime);
        std::cout << ball->getPosition().x << " " << ball->getPosition().y
                  << std::endl;
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
        std::cout << "paused" << std::endl;
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
        if (player->getPosition().y < minHeight) {
            player->setVelocity(0, 5);
            player->move(deltaTime);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (player->getPosition().y > maxHeight) {
            player->setVelocity(0, -5);
            player->move(deltaTime);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) gamePaused = true;

    while (gamePaused) {
        render_menu();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) gamePaused = false;
    }

    sf::Event event;
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
}

void Game::spawnObs() {
    Entity* newObs = new Obstacle();
    obs.push_back(newObs);
}

void Game::hit() {  // remember that the y-axis is flipped, down is positive and
                    // up negative. x-axis is OK

    for (int i = 0; i < obs.size(); i++) {
        if (ball->getGlobalBounds().intersects(
                dynamic_cast<Obstacle*>(obs[i])->getGlobalBounds())) {
            ball->setVelocity(ball->getVelocity().x * (-1),
                              ball->getVelocity().y * (1));
            obs.erase(obs.end() - (obs.size() - i));
            gameTime +=
                sf::seconds(dynamic_cast<Obstacle*>(obs[i])->getVertex());
        }
    }

    if (ball->getGlobalBounds().intersects(player->getGlobalBounds())) {
        ball->setVelocity(ball->getVelocity().x * (-1),
                          ball->getVelocity().y * (1));
    }

    if (ball->getGlobalBounds().intersects(top.getGlobalBounds())) {
        ball->setVelocity(ball->getVelocity().x * (1),
                          ball->getVelocity().y * (-1));
    }

    if (ball->getGlobalBounds().intersects(bot.getGlobalBounds())) {
        ball->setVelocity(ball->getVelocity().x * (1),
                          ball->getVelocity().y * (-1));
    }

    if (ball->getGlobalBounds().intersects(left.getGlobalBounds())) {
        ball->setVelocity(ball->getVelocity().x * (-1),
                          ball->getVelocity().y * (1));
        gameTime -= sf::seconds(3);
    }

    if (ball->getGlobalBounds().intersects(right.getGlobalBounds())) {
        ball->setVelocity(ball->getVelocity().x * (-1),
                          ball->getVelocity().y * (1));
    }
}
