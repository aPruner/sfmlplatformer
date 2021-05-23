#include "Level.h"

Level::Level() :
	m_vertexArray(new sf::VertexArray()),
	m_debugEnvArray(new std::vector<sf::RectangleShape>()) {
	fillDebugEnvArray();
}

Level::~Level() {
	delete m_vertexArray;
	delete m_debugEnvArray;
}

void Level::fillDebugEnvArray() {
	// For now, just create one rect for the ground
	sf::RectangleShape ground(sf::Vector2f(1000, 100));
	ground.setFillColor(sf::Color::Blue);
	ground.setPosition(sf::Vector2f(0, 800));
	m_debugEnvArray->push_back(ground);
}

sf::VertexArray* Level::getVertexArray() {
	return m_vertexArray;
}

std::vector<sf::RectangleShape>* Level::getDebugEnvArray() {
	return m_debugEnvArray;
}