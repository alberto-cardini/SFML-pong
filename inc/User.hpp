//
// Created by Alberto Cardini on 04/04/24.
//
#ifndef USER_hpp
#define USER_hpp

#include "Game.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

class User : public sf::Drawable, public sf::Transformable {
public:
    User();

    sf::Vector2f getPos() const ;
    sf::Sprite& getSprite();
    //sf::VertexArray& getShape();
    sf::RectangleShape & getShape();

    void setSpritePos(float x, float y);
    void setPlatformPos(float x, float y);

    void setPos(float x, float y);

private:

    sf::Texture pTexture;
    sf::Sprite pSprite;
    //sf::VertexArray platform;
    sf::RectangleShape platform;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &pTexture;
        target.draw(platform, states);
    }

};

#endif