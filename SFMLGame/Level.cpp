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
	m_backgroundSprite.setScale(sf::Vector2f(2, 2));
	m_backgroundSprite.setPosition(sf::Vector2f(0, 0));
}

void Level::fillDebugEnvArray() {
	sf::RectangleShape leftPlatform(sf::Vector2f(512, 384));
	leftPlatform.setFillColor(sf::Color::Transparent);
	leftPlatform.setOutlineColor(sf::Color::Blue);
	leftPlatform.setOutlineThickness(1.0);
	leftPlatform.setPosition(sf::Vector2f(128, 640));
	m_debugEnvArray->push_back(leftPlatform);

	sf::RectangleShape middlePlatform(sf::Vector2f(4 * 64, 4 * 64));
	middlePlatform.setFillColor(sf::Color::Transparent);
	middlePlatform.setOutlineColor(sf::Color::Blue);
	middlePlatform.setOutlineThickness(1.0);
	middlePlatform.setPosition(sf::Vector2f(11 * 64, 12 * 64));
	m_debugEnvArray->push_back(middlePlatform);

	sf::RectangleShape rightPlatform(sf::Vector2f(7 * 64, 1 * 64));
	rightPlatform.setFillColor(sf::Color::Transparent);
	rightPlatform.setOutlineColor(sf::Color::Blue);
	rightPlatform.setOutlineThickness(1.0);
	rightPlatform.setPosition(sf::Vector2f(15 * 64, 8 * 64));
	m_debugEnvArray->push_back(rightPlatform);
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