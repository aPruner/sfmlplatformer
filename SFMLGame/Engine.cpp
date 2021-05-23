#include "Engine.h"

Engine::Engine() {
	// Initialize everything except the clock, which needs to be
	// initialized in the run method
	m_clock = nullptr;

	// Create the window from the desktop screen resolution
	sf::VideoMode screenResolutionVM = sf::VideoMode::getDesktopMode();
	m_screenResolution = sf::Vector2f((float)screenResolutionVM.width, (float)screenResolutionVM.height);
	m_window = new sf::RenderWindow(screenResolutionVM, "NAME TBD", sf::Style::Fullscreen);

	m_game = new Game(new Player(), m_screenResolution);
}

// Input Helpers
void Engine::closeWindowInputHelper(sf::Event event) {
	if (event.type == sf::Event::Closed) {
		m_window->close();
	}

	if (event.type == sf::Event::KeyPressed) {
		// For now, escape quits the game
		if (event.key.code == sf::Keyboard::Escape) {
			m_window->close();
		}
	}
}

void Engine::movePlayerInputHelper() {
	Player* player = m_game->getPlayer();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player->setMoveLeftPressed(true);
	}
	else {
		player->setMoveLeftPressed(false);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player->setMoveRightPressed(true);
	}
	else {
		player->setMoveRightPressed(false);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		player->setJumpPressed(true);
	}
	else {
		player->setJumpPressed(false);
	}
}

void Engine::input() {
	sf::Event event;
	while (m_window->pollEvent(event)) {
		closeWindowInputHelper(event);
		movePlayerInputHelper();
	}
}

void Engine::update() {
	std::vector<GameObject*>* gameObjects = m_game->getGameObjects();
	sf::Time dt = m_clock->restart();
	float dtSeconds = dt.asSeconds();

	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		(*it)->update(dtSeconds);
	}

	m_game->centerGameViewOnPlayer();
}

void Engine::draw() {
	std::vector<GameObject*>* gameObjects = m_game->getGameObjects();
	m_window->clear();
	m_window->setView(m_game->getGameView());

	// Draw all rects in the debugEnvArray, acting as a level prototype
	std::vector<sf::RectangleShape>* debugEnvArray = m_game->getLevel()->getDebugEnvArray();
	for (auto it = debugEnvArray->begin(); it != debugEnvArray->end(); it++) {
		m_window->draw(*it);
	}

	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++) {
		GameObject *gameObject = *it;
		m_window->draw(*gameObject);
	}

	m_window->display();
}

void Engine::run() {
	// Start the clock
	m_clock = new sf::Clock();

	// Run the game loop
	while (m_window->isOpen())
	{
		input();
		update();
		draw();
	}
}