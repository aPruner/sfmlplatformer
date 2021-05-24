#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Level.h"

class Game {
private:
	std::vector<GameObject*>* m_gameObjects;

	Player* m_player;

	sf::View m_gameView;
	sf::View m_debugView;

	Level* m_level;

public:
	Game(Player* player, sf::Vector2f screenResolution, Level* level);
	~Game();

	void centerGameViewOnPlayer();
	void addGameObject(GameObject* gameObject);

	// Getters and setters
	std::vector<GameObject*>* getGameObjects();
	Player* getPlayer();
	sf::View getGameView();
	sf::View getDebugView();
	Level* getLevel();
};