#include "TextureMapper.h"

TextureMapper::TextureMapper() : m_textureMap(new std::map<std::string, sf::Texture>()) {
}

sf::Texture TextureMapper::getTexture(std::string textureName) {
	// TODO: error handling
	return m_textureMap->at(textureName);
}