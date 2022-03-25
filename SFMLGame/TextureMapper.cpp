#include "TextureMapper.h"

TextureMapper::TextureMapper() : m_textureMap(new std::map<std::string, sf::Texture>()) {
	fillTextureMap();
}

TextureMapper::~TextureMapper() {

}

sf::Texture TextureMapper::getTexture(std::string textureName) {
	auto searchTexture = m_textureMap->find(textureName);
	if (searchTexture != m_textureMap->end()) {
		return searchTexture->second;
	}
	// If the textureName wasn't found in the map, return an empty (unloaded) texture
	return sf::Texture();
}

void TextureMapper::fillTextureMap() {
	sf::Texture swampLevelTexture;
	swampLevelTexture.loadFromFile(SWAMP_LEVEL_FILEPATH);
	m_textureMap->emplace(std::pair<std::string, sf::Texture>(SWAMP_LEVEL_NAME, swampLevelTexture));
}

std::tuple<int, int, int, int, int> TextureMapper::getAnimTuple(std::string textureName) {
	// TODO: Implement this
	return std::tuple<int, int, int, int, int>(0, 0, 0, 0, 0);
}