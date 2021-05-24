#include "Game.h"

Game::Game(Player* player, sf::Vector2f screenResolution, Level* level) :
	m_player(player),
	m_gameObjects(new std::vector<GameObject*>()),
	m_gameView(sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y))),
	m_debugView(sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y))),
	m_level(level) {
	addGameObject(m_player);
	centerGameViewOnPlayer();
}

Game::~Game() {
	for (auto it = m_gameObjects->begin(); it != m_gameObjects->end(); it++) {
		delete (*it);
	}
	delete m_gameObjects;
	delete m_level;
}

void Game::centerGameViewOnPlayer() {
	m_gameView.setCenter(m_player->getPosition());
}

void Game::addGameObject(GameObject* gameObject) {
	m_gameObjects->push_back(gameObject);
}

std::vector<GameObject*>* Game::getGameObjects() {
	return m_gameObjects;
}

Player* Game::getPlayer() {
	return m_player;
}

sf::View Game::getGameView() {
	return m_gameView;
}

sf::View Game::getDebugView() {
	return m_debugView;
}

Level* Game::getLevel() {
	return m_level;
}