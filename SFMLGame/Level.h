#pragma once
#include <SFML/Graphics.hpp>
#include "TextureMapper.h"

// TODO: Maybe Level should extend sf::Drawable?
class Level : virtual public sf::Drawable {
private:
	sf::Sprite m_backgroundSprite;
	sf::Texture m_levelImage;

	TextureMapper* m_textureMapper;

	// LevelName for now is associated with the levelImage's texture name
	std::string m_levelName;

	// Array of rectangles representing the level environment
	// (for prototyping)
	std::vector<sf::RectangleShape>* m_debugEnvArray;

	void initBackgroundSprite();
	void fillDebugEnvArray();
	
public:
	Level(TextureMapper* textureMapper, std::string levelName);
	~Level();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters and setters
	sf::Sprite getBackgroundSprite();
	std::vector<sf::RectangleShape>* getDebugEnvArray();
};