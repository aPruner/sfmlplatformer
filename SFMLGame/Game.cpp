#include "Game.h"

Game::Game() {
	m_gameObjects = new std::vector<GameObject*>();
}

std::vector<GameObject*>* Game::getGameObjects() {
	return m_gameObjects;
}