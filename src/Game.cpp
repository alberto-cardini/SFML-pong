//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"
#include <iostream>

sf::Time Game::spawnTime = sf::seconds(5);
float Game::maxHeight = 150;  // counting 0 form the top
float Game::minHeight = 450;

Game::Game() : window(sf::VideoMode(800, 600), "Pong", sf::Style::Close) {
    window.setFramerateLimit(60);

    // HUD
    if (!font.loadFromFile("font/OpenSans-Regular.ttf")) {
        perror("Wrong working directory");
    }
    HUD.setFont(font);
    HUD.setPosition(100, 50);

    // Border
    top = sf::RectangleShape(sf::Vector2f(500, 6));
    bot = sf::RectangleShape(sf::Vector2f(500, 6));
    right = sf::RectangleShape(sf::Vector2f(6, 412));
    left = sf::RectangleShape(sf::Vector2f(6, 412));

    left.setFillColor(sf::Color::Red);

    top.setOrigin(250, 3);
    bot.setOrigin(250, 3);

    right.setOrigin(3, 200);
    left.setOrigin(3, 200);

    top.setPosition(400, 97);
    bot.setPosition(400, 503);

    left.setPosition(147, 294);
    right.setPosition(653, 294);

    // Entities
    player = User();
    ball = Ball();

    // Time
    dtClock = sf::Clock();
    gameClock = sf::Clock();
    spawnClock = sf::Clock();
    gameTime = sf::seconds(20);
}

void Game::renderHUD() {
    sf::String string =
        "TIME LEFT: " +
        std::to_string(static_cast<int>(
            gameTime.asSeconds() - gameClock.getElapsedTime().asSeconds())) +
        " sec.";
    HUD.setString(string);
    window.draw(top);
    window.draw(bot);
    window.draw(right);
    window.draw(left);
}

void Game::render() {
    window.clear();
    renderHUD();
    window.draw(HUD);
    window.draw(ball);
    window.draw(player);
    for (const Obstacle& n : obs) {
        window.draw(n);
        // window.draw(n.timeGain);
    }
    window.display();
}

void Game::update() {
    if (gameClock.getElapsedTime().asSeconds() < gameTime.asSeconds()) {
        deltaTime = dtClock.restart();
        ball.move(deltaTime);
        hit();
        static long seed;
        seed = std::time(nullptr) + seed;
        srand(seed);
        if (static_cast<int>(spawnClock.getElapsedTime().asSeconds() -
                             spawnTime.asSeconds()) == 0) {
            spawnClock.restart();
            spawnObs();
        }
    } else {
        gameClock.restart();
        restart();
    }
}

void Game::restart() {
    gameTime = sf::seconds(20);
    gameClock.restart();
    ball.setPosition(400, 300);
    obs.clear();
}

void Game::manageEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:

                switch (event.key.scancode) {
                    case sf::Keyboard::Scan::S:
                        if (player.getPosition().y + 20 < minHeight)
                            player.move(0, 20);
                        break;

                    case sf::Keyboard::Scan::W:
                        if (player.getPosition().y - 20 > maxHeight)
                            player.move(0, -20);
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void Game::run() {
    while (window.isOpen()) {
        manageEvent();
        update();
        render();
    }
}

void Game::spawnObs() {
    Obstacle newObs;
    obs.push_back(newObs);
}

void Game::hit() {  // remember that the y-axis is flipped, down is positive and
                    // up negative. x-axis is OK

    for (int i = 0; i < obs.size(); i++) {
        if (ball.getGlobalBounds().intersects(obs[i].getGlobalBounds())) {
            ball.setVelocity(ball.getVelocity().x * (-1),
                             ball.getVelocity().y * (1));
            obs.erase(obs.end() - (obs.size() - i));
            gameTime += obs[i].getTimeGain();
        }
    }

    if (ball.getGlobalBounds().intersects(player.getGlobalBounds())) {
        ball.setVelocity(ball.getVelocity().x * (-1),
                         ball.getVelocity().y * (1));
    }

    if (ball.getGlobalBounds().intersects(top.getGlobalBounds())) {
        ball.setVelocity(ball.getVelocity().x * (1),
                         ball.getVelocity().y * (-1));
    }

    if (ball.getGlobalBounds().intersects(bot.getGlobalBounds())) {
        ball.setVelocity(ball.getVelocity().x * (1),
                         ball.getVelocity().y * (-1));
    }

    if (ball.getGlobalBounds().intersects(left.getGlobalBounds())) {
        ball.setVelocity(ball.getVelocity().x * (-1),
                         ball.getVelocity().y * (1));
        gameTime -= sf::seconds(3);
    }

    if (ball.getGlobalBounds().intersects(right.getGlobalBounds())) {
        ball.setVelocity(ball.getVelocity().x * (-1),
                         ball.getVelocity().y * (1));
    }
}
