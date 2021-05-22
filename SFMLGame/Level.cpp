#include "Level.h"

Level::Level() {
	m_levelVertexArray = new sf::VertexArray();
}

Level::~Level() {
	delete m_levelVertexArray;
}

sf::VertexArray* Level::getLevelVertexArray() {
	return m_levelVertexArray;
}