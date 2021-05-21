#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Engine {
private:

	sf::RenderWindow* m_window;
	sf::View* m_gameView;
	sf::Clock* m_clock;
	Game* m_game;

	sf::Vector2f m_screenResolution;

	void input();
	void update(std::vector<GameObject*>* gameObjects);
	void draw(std::vector<GameObject*>* gameObjects);

public:
	Engine();

	void run();
};