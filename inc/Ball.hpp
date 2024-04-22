//
// Created by Alberto Cardini on 04/04/24.
//

#ifndef BALL_hpp
#define BALL_hpp

#include "Entity.hpp"

class Ball : public Entity {
public:

    Ball();

    void move(sf::Time dt) override;

private:
    // TODO asser manager
};

#endif