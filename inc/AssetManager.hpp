//
// Created by Alberto Cardini on 01/05/24.
//

#ifndef SFML_PONG_ASSETMANAGER_HPP
#define SFML_PONG_ASSETMANAGER_HPP

#include "SFML/Graphics.hpp"

class AssetManager {
public:
    AssetManager();
    static sf::Texture& getTexture(const std::string& filename);
    static sf::Font& getFont(const std::string& filename);

private:
    std::map<std::string, sf::Texture> textureMap;
    std::map<std::string, sf::Font> fontMap;
    static AssetManager* assetManager;
};

#endif  // SFML_PONG_ASSETMANAGER_HPP
