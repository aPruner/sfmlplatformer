#include "Engine.h"

Engine::Engine() {
	// Initialize everything except the clock, which needs to be
	// initialized in the run method

	// Create the window from the desktop screen resolution
	sf::VideoMode screenResolutionVM = sf::VideoMode::getDesktopMode();
	m_screenResolution = sf::Vector2f((float)screenResolutionVM.width, (float)screenResolutionVM.height);
	m_window = new sf::RenderWindow(screenResolutionVM, "NAME TBD", sf::Style::Fullscreen);

	m_game = new Game();
}

void Engine::input() {
	sf::Event event;
	while (m_window->pollEvent(event)) {
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
}

void Engine::update(std::vector<GameObject*>* gameObjects) {

}

void Engine::draw(std::vector<GameObject*>* gameObjects) {
	m_window->clear();

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
		std::vector<GameObject*>* gameObjects = m_game->getGameObjects();
		input();
		update(gameObjects);
		draw(gameObjects);
	}
}