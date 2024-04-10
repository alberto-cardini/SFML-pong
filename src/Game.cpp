//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"
#include <iostream>

int Game::score = 0;
float Game::maxHeight = 150;  //counting 0 form the top
float Game::minHeight = 450;

Game::Game() : window(sf::VideoMode(800, 600), "Pong", sf::Style::Close) {

    window.setFramerateLimit(60);

    //HUD
    if(!font.loadFromFile("font/OpenSans-Regular.ttf")){
        perror("Wrong working directory");
    }
    scoreText.setFont(font);
    scoreText.setPosition(100,50);

    //Border
    top = sf::RectangleShape(sf::Vector2f(500, 6));
    bot = sf::RectangleShape(sf::Vector2f(500, 6));
    right = sf::RectangleShape(sf::Vector2f(6, 412));
    left = sf::RectangleShape(sf::Vector2f(6, 412));

    top.setOrigin(250,3);
    bot.setOrigin(250,3);

    right.setOrigin(3,200);
    left.setOrigin(3,200);

    top.setPosition(400,97);
    bot.setPosition(400,503);

    left.setPosition(147,294);
    right.setPosition(653,294);

    //Entities
    player = User();
    ball = Ball();

    //Time
    clock = sf::Clock();
}

void Game::renderHUD() {
    sf::String string = "SCORE: " + std::to_string(score);
    scoreText.setString(string);
    window.draw(top);
    window.draw(bot);
    window.draw(right);
    window.draw(left);
}

void Game::render(){
    window.clear();
    renderHUD();
    window.draw(scoreText);
    window.draw(ball);
    window.draw(player);
    window.display();
}

void Game::update() {
    ball.move(deltaTime);
    hit();
}

void Game::restart(){
    score = 0;
    ball.setPosition(400, 300);
}

void Game::eventManager(){
    sf::Event event;
    while(window.pollEvent(event)){
        switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:

                switch (event.key.scancode) {

                    case sf::Keyboard::Scan::Down:
                        if(player.getPosition().y + 20 < minHeight)
                            player.move(0,20);
                        std::cout << player.getPosition().y << std::endl;
                        break;

                    case sf::Keyboard::Scan::Up:
                        if(player.getPosition().y - 20 > maxHeight)
                            player.move(0, -20);
                        std::cout << player.getPosition().y << std::endl;
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

void Game::run(){
    while(window.isOpen()){
        deltaTime = clock.restart();
        eventManager();
        update();
        render();
    }
}

void Game::hit(){  // remember that the y-axis is flipped, down is positive and up negative. x-axis is OK
    if(ball.getGlobalBounds().intersects(player.getGlobalBounds())){
        ball.setVelocity(ball.getVelocity().x * (-1), ball.getVelocity().y * (1));
        score++;
    }
    if(ball.getGlobalBounds().intersects(top.getGlobalBounds())){
        ball.setVelocity(ball.getVelocity().x * (1), ball.getVelocity().y * (-1));
    }
    if(ball.getGlobalBounds().intersects(bot.getGlobalBounds())){
        ball.setVelocity(ball.getVelocity().x * (1), ball.getVelocity().y * (-1));
    }
    if(ball.getGlobalBounds().intersects(left.getGlobalBounds())){
        restart();
    }
    if(ball.getGlobalBounds().intersects(right.getGlobalBounds())){
        ball.setVelocity(ball.getVelocity().x * (-1), ball.getVelocity().y * (1));
    }
}
