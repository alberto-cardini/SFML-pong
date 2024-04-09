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
    player.getShape().setFillColor(sf::Color::Red);
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
                        if(player.getShape().getPosition().y < minHeight)
                            player.getShape().move(0,20);
                        break;

                    case sf::Keyboard::Scan::Up:
                        if(player.getShape().getPosition().y > maxHeight)
                            player.getShape().move(0, -20);
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

void Game::hit(){
    sf::FloatRect area;
    if(ball.getShape().getGlobalBounds().intersects(player.getShape().getGlobalBounds())){
        ball.setDirection(ball.getDirection().x * (-1), 0);
        score++;
    }
    if(ball.getShape().getGlobalBounds().intersects(top.getGlobalBounds(), area)){
        std::cout << ball.getPosition().x << std::endl;
        ball.setDirection(ball.getDirection().x * (-1), 0);
    }
    if(ball.getShape().getGlobalBounds().intersects(bot.getGlobalBounds(), area)){
        std::cout << ball.getPosition().x << std::endl;
        ball.setDirection(ball.getDirection().x * (-1), 0);
    }
    if(ball.getShape().getGlobalBounds().intersects(left.getGlobalBounds(), area)){
        std::cout << ball.getPosition().x << std::endl;
        ball.setDirection(ball.getDirection().x * (-1), 0);
        score--;
    }
    if(ball.getShape().getGlobalBounds().intersects(right.getGlobalBounds(), area)){
        std::cout << ball.getPosition().x << std::endl;
        ball.setDirection(ball.getDirection().x * (-1), 0);
    }
}
