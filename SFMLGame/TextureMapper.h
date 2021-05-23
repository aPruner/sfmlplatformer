#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

// Class used to access various texture atlases
class TextureMapper {
private:
	std::map<std::string, sf::Texture>* m_textureMap;

public:
	TextureMapper();

	sf::Texture getTexture(std::string textureName);
};