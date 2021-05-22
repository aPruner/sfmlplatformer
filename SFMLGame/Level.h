#pragma once
#include <SFML/Graphics.hpp>

class Level {
private:
	sf::VertexArray* m_levelVertexArray;
public:
	Level();
	~Level();

	// Getters and setters
	sf::VertexArray* getLevelVertexArray();
};