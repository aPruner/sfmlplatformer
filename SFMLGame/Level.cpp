#include "Level.h"

Level::Level(TextureMapper* textureMapper, std::string levelName) :
	m_textureMapper(textureMapper),
	m_levelName(levelName),
	m_levelImage(textureMapper->getTexture(levelName)),
	m_debugEnvArray(new std::vector<sf::RectangleShape>()) {
	initBackgroundSprite();
	fillDebugEnvArray();
}

Level::~Level() {
	delete m_debugEnvArray;
}

void Level::initBackgroundSprite() {
	m_backgroundSprite.setTexture(m_levelImage);
	// By default, levelImages are tiled in 16x16, so they need to be scaled to 32x32
	// m_backgroundSprite.setScale(sf::Vector2f(1, 1));
	m_backgroundSprite.setPosition(sf::Vector2f(0, 0));
}

void Level::fillDebugEnvArray() {
	// For now, just create one rect for the ground
	sf::RectangleShape ground(sf::Vector2f(1000, 100));
	ground.setFillColor(sf::Color::Blue);
	ground.setPosition(sf::Vector2f(0, 800));
	m_debugEnvArray->push_back(ground);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_backgroundSprite, states);
	for (auto it = m_debugEnvArray->begin(); it != m_debugEnvArray->end(); it++) {
		target.draw(*it, states);
	}
}

sf::Sprite Level::getBackgroundSprite() {
	return m_backgroundSprite;
}

std::vector<sf::RectangleShape>* Level::getDebugEnvArray() {
	return m_debugEnvArray;
}