#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Engine {
private:

	sf::RenderWindow* m_window;
	sf::Clock* m_clock;
	Game* m_game;

	sf::Vector2f m_screenResolution;

	// Input helpers
	void closeWindowInputHelper(sf::Event event);
	void movePlayerInputHelper(sf::Event event);

	// Update helpers
	// TODO: add these if necessary

	// Draw helpers
	// TODO: add these when necessary

	void input();
	void update();
	void draw();

public:
	Engine();

	void run();
};