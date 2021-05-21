#pragma once
#include "GameObject.h"

class Game {
private:
	std::vector<GameObject*>* m_gameObjects;

public:
	Game();

	// Getters and setters
	std::vector<GameObject*>* getGameObjects();

};