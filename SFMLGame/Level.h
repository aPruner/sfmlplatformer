#pragma once
#include <SFML/Graphics.hpp>

// TODO: Maybe Level should extend sf::Drawable?
class Level {
private:
	sf::VertexArray* m_vertexArray;

	// Array of rectangles representing the level environment
	// (for prototyping)
	std::vector<sf::RectangleShape>* m_debugEnvArray;

	void fillDebugEnvArray();
	
public:
	Level();
	~Level();

	// Getters and setters
	sf::VertexArray* getVertexArray();
	std::vector<sf::RectangleShape>* getDebugEnvArray();
};