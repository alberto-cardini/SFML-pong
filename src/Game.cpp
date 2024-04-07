//
// Created by Alberto Cardini on 04/04/24.
//
#include "Game.hpp"
#include <iostream>

int Game::score = 0;
float Game::maxHeight = 150;  //counting 0 form the top
float Game::minHeight = 450;

Game::Game() : window(sf::VideoMode(800, 600), "Pong"),
                border(sf::Vector2f (500.f, 400.f)) {

    window.setFramerateLimit(60);

    if(!font.loadFromFile("textures/OpenSans-Bold.ttf"))
        perror("File not found");
    HUD.setFont(font);
    HUD.setPosition(100, 50);

    border.setOrigin(250.f, 200.f);
    border.setPosition(400.f, 300.f);
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOutlineThickness(5.f);

}

void Game::render(){
    sf::String interface = "SCORE: " + std::to_string(score);
    HUD.setString(interface);
    window.clear();
    window.draw(HUD);
    window.draw(border);
    window.draw(ball);
    window.draw(player);
    window.display();
}

void Game::update() {
    ball.getShape().move(ball.getDirection().x,0);
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

    player = User();
    ball = Ball();

    while(window.isOpen()){
        eventManager();
        update();
        render();
    }
}

bool Game::hit(){
    sf::FloatRect area;
    if(ball.getShape().getGlobalBounds().intersects(player.getShape().getGlobalBounds())){
        ball.setDirection(ball.getDirection().x * (-1), 0);
        score++;
    }
    if(!ball.getShape().getGlobalBounds().intersects(border.getGlobalBounds(), area)){
        ball.setDirection(ball.getDirection().x * (-1), 0);
    }
}
