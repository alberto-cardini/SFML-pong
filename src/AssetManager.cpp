//
// Created by Alberto Cardini on 01/05/24.
//

#include "AssetManager.hpp"
#include <map>

AssetManager* AssetManager::assetManager = nullptr;

AssetManager::AssetManager() {
    if (assetManager != nullptr) {
        abort();
    }
    assetManager = this;
}

sf::Texture& AssetManager::getTexture(const std::string& filename) {
    auto& texMap = assetManager->textureMap;
    auto pairFound = texMap.find(filename);
    if (pairFound != texMap.end()) {
        return pairFound->second;
    } else {
        auto& texture = texMap[filename];
        texture.loadFromFile("asset/" + filename + ".png");
        return texture;
    }
}

sf::Font& AssetManager::getFont(const std::string& filename) {
    auto& texMap = assetManager->fontMap;
    auto pairFound = texMap.find(filename);
    if (pairFound != texMap.end()) {
        return pairFound->second;
    } else {
        auto& font = texMap[filename];
        font.loadFromFile("asset/" + filename + ".ttf");
        return font;
    }
}