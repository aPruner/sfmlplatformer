#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

// Class used to access various texture atlases
class TextureMapper {
private:
	std::map<std::string, sf::Texture>* m_textureMap;

	void fillTextureMap();

public:
	TextureMapper();
	~TextureMapper();

	sf::Texture getTexture(std::string textureName);

	std::tuple<int, int, int, int, int> getAnimTuple(std::string textureName);

	// Texture atlas (aka sprite sheet) filepath and name constants

	// Levelimage filepath and name constants
	inline static const std::string SWAMP_LEVEL_FILEPATH = "Assets/LevelImages/swampLevel.png";
	inline static const std::string SWAMP_LEVEL_NAME = "swampLevel";
};