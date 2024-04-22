//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef USER_hpp
#define USER_hpp

#include "Entity.hpp"

class User : public Entity {
public:

    User();

    void move(sf::Time deltaTime) override;

private:

};

#endif